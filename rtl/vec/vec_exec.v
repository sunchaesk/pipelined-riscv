
module vec_exec #(
                  parameter VLEN = 256,
                  parameter NUM_PE = 4
                  )(
                    input                 clk,
                    input                 reset,
                    input                 new_instr, // reset count to 0
                    input [2:0]           vsew,
                    input [5:0]           funct6,
                    input [VLEN-1:0]      operand_a,
                    input [VLEN-1:0]      operand_b,
                    output reg [VLEN-1:0] vec_exec_out,
                    output reg            vec_op_done
                    );

   localparam                             VSEW_8 = 3'b000;
   localparam                             VSEW_16 = 3'b001;
   localparam                             VSEW_32 = 3'b010;
   localparam                             VSEW_64 = 3'b011;


   reg [3:0]                              state;
   reg [31:0]                             count; // can use a much smaller reg dont need 32 bits (max(vlen) / min(vsew))
   integer                                num_cycles_needed;
   integer                                i;


   reg [63:0]                             pe_a [NUM_PE-1:0];
   reg [63:0]                             pe_b [NUM_PE-1:0];
   wire [63:0]                            pe_result [NUM_PE-1:0];

   generate
      genvar                              pe_idx;
      for (pe_idx = 0; pe_idx < NUM_PE; pe_idx = pe_idx + 1) begin : pe_block
         vec_processing_element pe (
                                    .a(pe_a[pe_idx]),
                                    .b(pe_b[pe_idx]),
                                    .funct6(funct6),
                                    .result(pe_result[pe_idx])
                                    );
      end
   endgenerate

   always @(*) begin
      case (vsew)
        VSEW_8: num_cycles_needed = VLEN >> ($clog2(8 * NUM_PE));
        VSEW_16: num_cycles_needed = VLEN >> ($clog2(16 * NUM_PE));
        VSEW_32: num_cycles_needed = VLEN >> ($clog2(32 * NUM_PE));
        VSEW_64: num_cycles_needed = VLEN >> ($clog2(64 * NUM_PE));
        default: num_cycles_needed = VLEN >> ($clog2(32 * NUM_PE));
      endcase
   end


   always @(*) begin
      for (i = 0; i < NUM_PE; i = i + 1) begin
         case (vsew)
           VSEW_8: begin
              pe_a[i] = operand_a[(count * NUM_PE + i) * 8 +: 8];
              pe_b[i] = operand_b[(count * NUM_PE + i) * 8 +: 8];
           end
           VSEW_16: begin
              pe_a[i] = operand_a[(count * NUM_PE + i) * 16 +: 16];
              pe_b[i] = operand_b[(count * NUM_PE + i) * 16 +: 16];
           end
           VSEW_32: begin
              pe_a[i] = operand_a[(count * NUM_PE + i) * 32 +: 32];
              pe_b[i] = operand_b[(count * NUM_PE + i) * 32 +: 32];
           end
           VSEW_64: begin
              pe_a[i] = operand_a[(count * NUM_PE + i) * 64 +: 64];
              pe_b[i] = operand_b[(count * NUM_PE + i) * 64 +: 64];
           end
           default: begin
              pe_a[i] = operand_a[(count * NUM_PE + i) * 32 +: 32];
              pe_b[i] = operand_b[(count * NUM_PE + i) * 32 +: 32];
           end
         endcase
      end
   end

   always @(posedge clk or posedge reset) begin
      if (reset || new_instr) begin
         vec_exec_out <= {VLEN{1'b0}};
         count <= 0;
         vec_op_done <= 0;
      end else begin
         if (count < num_cycles_needed) begin
            for (i = 0; i < NUM_PE; i = i + 1) begin
               case (vsew)
                 VSEW_8: vec_exec_out[(count * NUM_PE + i) * 8 +: 8] <= pe_result[i][7:0];
                 VSEW_16: vec_exec_out[(count * NUM_PE + i) * 16 +: 16] <= pe_result[i][15:0];
                 VSEW_32: vec_exec_out[(count * NUM_PE + i) * 32 +: 32] <= pe_result[i][31:0];
                 VSEW_64: vec_exec_out[(count * NUM_PE + i) * 64 +: 64] <= pe_result[i][63:0];
                 default: vec_exec_out[(count * NUM_PE + i) * 32 +: 32] <= pe_result[i][31:0];
               endcase
            end
            count <= count + 1;
         end else if (count == num_cycles_needed) begin // if (count < cycles_needed)
            vec_op_done <= 1;
         end
      end

   end

endmodule

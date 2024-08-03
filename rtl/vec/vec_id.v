
// NOTE: zimm doesn't need sign extension
// NOTE: vec_src_d == 0 -> vec reg value
// vec_src_d == 1 -> register values
// vec_src_d == 2 -> imm
module vec_id #(
                parameter VLEN = 256
                )(
                  input wire            clk,
                  input wire            reset,
                  input wire [31:0]     instruction,
                  input wire [VLEN-1:0] vec_writeback_data,
                  output reg [4:0]      vec_rd,
                  output reg [VLEN-1:0] vec_rs1_out,
                  output reg [VLEN-1:0] vec_rs2_out,
                  output reg [10:0]     vec_imm,
                  output wire           vec_regwrite_d,
                  output wire [1:0]     vec_src_d // controls whether input is reg or vec
                  );

   localparam                           OP_LOAD = 7'b0000111;
   localparam                           OP_STORE = 7'b0100111;
   localparam                           OP_ARITH =  7'b1010111;

   reg [VLEN-1:0]                       vec_reg_array [31:0]; // vector register definition


   wire [6:0]                           opcode;
   wire [4:0]                           vd;
   wire [2:0]                           width;
   wire [4:0]                           lumop;
   wire [4:0]                           vrs1; // can also be u/s imm for vi type instrs
   wire [4:0]                           vrs2;
   wire                                 vm;
   wire [2:0]                           mop;
   wire [2:0]                           nf;
   wire [10:0]                          zimm;
   wire [5:0]                           funct6;

   wire                                 vec_regwrite_temp;
   wire                                 vec_src_temp;


   integer                              i;

   assign opcode = instruction[6:0];
   assign vd = instruction[11:7];
   assign width = instruction[14:12];
   assign rs1 = instruction[19:15];
   assign rs2 = instruction[24:20];
   assign lumop = instruction[24:20];
   assign vm = instruction[25];
   assign mop = instruction[28:26];
   assign nf = instruction[31:29];
   assign zimm = instruction[30:20];
   assign funct6 = instruction[31:26];

   always @(posedge clk or posedge reset) begin
      if (reset) begin
         vec_rd <= 5'b0;
         vec_rs1_out <= {VLEN{1'b0}};
         vec_rs2_out <= {VLEN{1'b0}};
         vec_imm <= 10'b0;
         vec_src_d <= 2'b0;
         vec_regwrite_d <= 1'b0;
      end else begin
         vec_rd <= vd;
         vec_vrs1_out <= vec_reg_array[vrs1];
         vec_vrs2_out <= vec_reg_array[vrs2];
         vec_imm <= zimm;
         vec_src_d <= vec_src_temp;
         vec_regwrite_d <= vec_regwrite_temp;
      end
   end

   always @(negedge clk or posedge reset) begin
      if (reset) begin
         for (i = 0; i < 32; i = i + 1) begin
            vec_reg_array[i] <= 256'b0;
         end
      end else if (vec_writeback_control) begin
         if (vec_rd != 5'b0) begin
            vec_reg_array[vec_rd] <= vec_writeback_data;
         end
      end
   end

   // control signals
   assign vec_src_temp = (width == 3'b000) ? 2'b00 : // vv type
                      (width == 3'b100) ? 2'b01 : // vx type
                      (width == 3'b011) ? 2'b10 : 2'b00;
   assign vec_regwrite_temp = (opcode ==  OP_ARITH) ? 1'b1 : 1'b0; // only enable vec_regwrite_d if OP_ARITH

endmodule

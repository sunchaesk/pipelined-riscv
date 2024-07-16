module WB (
           input              clk,
           input              reset,
           input              regwrite_w,
           input [1:0]        result_src_w,
           input [31:0]       alu_result_w,
           input [31:0]       readdata_w,
           input [4:0]        rd_w,
           input [31:0]       pc_plus_4_w,
           // output
           output reg         wb_regwrite,
           output reg [4:0]   wb_rd,
           output reg [31:0]  wb_result,
           output wire [31:0] mem_wb_result
           );

   assign mem_wb_result = (result_src_w == 2'b00) ? alu_result_w :
                          (result_src_w == 2'b01) ? readdata_w :
                          (result_src_w == 2'b10) ? pc_plus_4_w :
                          32'b0; // default case

   always @(posedge clk or posedge reset) begin
      if (reset) begin
         wb_regwrite <= 1'b0;
         wb_rd <= 5'b0;
         wb_result <= 32'b0; // Initialize to zero on reset
      end else begin
         wb_regwrite <= regwrite_w;
         wb_rd <= rd_w;

         // MUX for result_src
         case(result_src_w)
           2'b00: wb_result <= alu_result_w;
           2'b01: wb_result <= readdata_w;
           2'b10: wb_result <= pc_plus_4_w;
           default: wb_result <= 32'b0; // Default case for safety
         endcase
      end
   end
endmodule

// module WB (
//            input             clk,
//            input             reset,
//            input             regwrite_w,
//            input [1:0]       result_src_w,
//            input [31:0]      alu_result_w,
//            input [31:0]      readdata_w,
//            input [4:0]       rd_w,
//            input [31:0]      pc_plus_4_w,
//            // output
//            output reg        wb_regwrite,
//            output reg [4:0]  wb_rd,
//            output reg [31:0] wb_result
//            );

//    always @(posedge clk or posedge reset) begin
//    // always @(*) begin
//       if (reset) begin
//          wb_regwrite <= 1'b0;
//          wb_rd <= 5'b0;
//          wb_result <= 32'b0; // Initialize to zero on reset
//       end else begin
//          wb_regwrite <= regwrite_w;
//          wb_rd <= rd_w;

//          // MUX for result_src
//          case(result_src_w)
//             2'b00: wb_result <= alu_result_w;
//             2'b01: wb_result <= readdata_w;
//             2'b10: wb_result <= pc_plus_4_w;
//             default: wb_result <= 32'b0; // Default case for safety
//          endcase
//       end
//    end

// endmodule


module MEM (
            input             clk,
            input             reset,
            input             regwrite_m,
            input [1:0]       result_src_m,
            input             memwrite_m,
            input [31:0]      alu_result_m,
            input [31:0]      writedata_m,
            input [4:0]       rd_m,
            input [31:0]      pc_plus_4_m,

            output reg [31:0] readdata,
            //forward
            output reg        mem_wb_regwrite,
            output reg [1:0]  mem_wb_result_src,
            output reg [31:0] mem_wb_alu_result,
            output reg [31:0] mem_wb_pc_plus_4,
            output reg [4:0]  mem_wb_rd,
            output            mem_regwrite_m,
            output [31:0]     mem_alu_result_m
            );

   assign mem_regwrite_m = regwrite_m;
   assign mem_alu_result_m = alu_result_m;

   reg [31:0]                 mem_array [0:31];

   always @(posedge clk or posedge reset) begin
      if (reset) begin
         mem_wb_regwrite <= 1'b0;
         mem_wb_result_src <= 2'b0;
         mem_wb_alu_result <= 32'b0;
         mem_wb_pc_plus_4 <= 32'b0;
         mem_wb_rd <= 5'b0;
         readdata <= 32'b0;
         // mem_regwrite_m <= 1'b0;
      end else begin
         mem_wb_regwrite <= regwrite_m;
         mem_wb_result_src <= result_src_m;
         mem_wb_alu_result <= alu_result_m;
         mem_wb_pc_plus_4 <= pc_plus_4_m;
         mem_wb_rd <= rd_m;
         //mem_regwrite_m <= regwrite_m;

         //read memory
         readdata <= mem_array[alu_result_m >> 2]; // TODO do i >> 2?

         // write memory
         if (memwrite_m) begin
            mem_array[alu_result_m >> 2] <= writedata_m;
         end
      end

   end


endmodule

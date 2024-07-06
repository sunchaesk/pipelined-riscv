
module WB (
           input             mem_to_reg,
           input [31:0]      alu_result,
           input [31:0]      mem_data,
           output reg [31:0] wb_data
           );

   always @(*) begin
      if (mem_to_reg) begin
         wb_data = mem_data;
      end else begin
         wb_data = alu_result;
      end
   end

endmodule

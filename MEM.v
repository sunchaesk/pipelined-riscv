
module MEM (
            input             clk,
            input             reset,
            input             mem_write,
            input             mem_read,
            input [31:0]      pc_next_jump_branch,
            input [31:0]      alu_result,
            input [31:0]      rs2_data,
            output reg [31:0] mem_data
            );

   reg [31:0]                 mem_array [0:1024];

   always @(posedge clk or posedge reset) begin
      if (reset) begin
         mem_data <= 32'b0;
      end else begin
         if (mem_read) begin
            mem_data <= mem_array[alu_result >> 2];
         end else if (mem_write) begin
            mem_array[alu_result >> 2] <= rs2_data;
         end
      end
   end

endmodule

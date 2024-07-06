module IF (
           input             clk,
           input             reset,
           output reg [31:0] pc,
           output reg [31:0] instr
           );

   reg [31:0]                instr_mem [0:255];

   always @(posedge clk or posedge reset) begin
      if (reset) begin
         pc <= 0;
         instr <= 0;
      end else begin
         pc <= pc + 4;
         instr <= instr_mem[pc >> 2]; // word aligned
      end
   end


endmodule

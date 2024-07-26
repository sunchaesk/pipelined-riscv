
module test (
             input clk,
             input reset,
             input [31:0] in_a,
             input [31:0] in_b,
             output [31:0] out
             );

   // wire [31:0]     in_a;
   // wire [31:0]     in_b;

   // wire [31:0]     out;


   fpu_top uut (
            .clk(clk),
            .reset(reset),
            .in_a(in_a),
            .in_b(in_b),
            .out(out)
                );


endmodule

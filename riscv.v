
module riscv (
              input         clk,
              input         reset,
              input [31:0]  in_a,
              input [31:0]  in_b,
              input [3:0]   alu_control,
              output        zero_flag,
              output [31:0] alu_result
              );

   wire                     clk_test;
   wire                     reset_test;

   assign clk_test = clk;
   assign reset_test = reset;

   alu alu_unit (
                 .in_a(in_a),
                 .in_b(in_b),
                 .alu_control(alu_control),
                 .alu_result(alu_result),
                 .zero_flag(zero_flag)
                 );

endmodule

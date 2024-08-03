
module test (
             input          clk,
             input          reset,
             input          new_instr,
             input [2:0]    vsew,
             input [5:0]    funct6,
             input [255:0]  operand_a,
             input [255:0]  operand_b,
             output [255:0] vec_exec_out,
             output         vec_op_done
             );

   vec_exec #(
              .VLEN(256),
              .NUM_PE(4)
              ) uut (
                     .clk(clk),
                     .reset(reset),
                     .new_instr(new_instr),
                     .vsew(vsew),
                     .funct6(funct6),
                     .operand_a(operand_a),
                     .operand_b(operand_b),
                     .vec_exec_out(vec_exec_out),
                     .vec_op_done(vec_op_done)
                     );



endmodule

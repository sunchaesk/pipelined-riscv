
module test (
             input          clk,
             input          reset,
             input          new_instr,
             input          vec_regwrite_d,
             input [1:0]    vec_src_d,
             input [2:0]    vsew,
             input [5:0]    funct6,
             input [4:0]    imm,
             input [31:0]   reg_val,
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
                     .vec_src_d(vec_src_d),
                     .vsew(vsew),
                     .funct6(funct6),
                     .v_operand_a(operand_a),
                     .v_operand_b(operand_b),
                     .v_imm(imm),
                     .v_reg(reg_val),
                     .vec_exec_out(vec_exec_out),
                     .vec_op_done(vec_op_done)
                     );



endmodule

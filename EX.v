
// pass -> refers to just passing the value to the forward
module EX (
           input
           );

   wire [31:0]           operand_a;
   wire [31:0]           operand_b;

   assign operand_a = rs1_data;
   assign operand_b = alu_src ? imm : rs2_data;

   assign rs2_data_pass = rs2_data;
   assign rd_pass = rd;


   ALU ALU_unit (
                 .in_a(operand_a),
                 .in_b(operand_b),
                 .alu_control(alu_control),
                 .alu_result(alu_result),
                 .zero_flag(zero_flag)
                 );

   // calculate next jump/branch pc
   assign pc_next_jump_branch = pc + (imm << 2);
endmodule

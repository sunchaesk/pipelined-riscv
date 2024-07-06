
// pass -> refers to just passing the value to the forward
module EX (
           input         alu_src,
           input [3:0]   alu_control,
           input [4:0]   rd,
           input [31:0]  pc,
           input [31:0]  imm,
           input [31:0]  rs1_data,
           input [31:0]  rs2_data,
           output        zero_flag,
           output [3:0]  rd_pass,
           output [31:0] alu_result,
           output [31:0] rs2_data_pass, // rs2_data passed out
           output [31:0] pc_next_jump_branch // pc in case of branching/jumping
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

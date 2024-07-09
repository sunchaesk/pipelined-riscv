
/*
 branch_condition module is for deciding whether the IFU should branch (change the PC or not)

 Two conditions are checked:
 - If the instruction itself is a branching instruction: Only opcode that corresponds to B-type instruction will eval as 1.
 will turn the branch_instruction_control reg as 1
 - The actual branch condition is evaluated by the branch_condition unit.
 This is either return the branch_flag flag as 1 or 0

 - Once both of these flags are evaluated, the branch_taken flag of the IFU which
 determines whether the branch should happen is only turned on if both the
 branch_instruction_control and branch_flag flags are both 1.
 - branch_taken = branch_flag && branch_instruction_control

 */

module branch_condition (
                         input [31:0] in_a,
                         input [31:0] in_b,
                         input [2:0]  branch_control,
                         output reg   branch_flag
                         );

   always @(*) begin
      case (branch_control) // funct3
        3'b000: branch_flag = (in_a == in_b); // BEQ
        3'b001: branch_flag = (in_a != in_b); // BNE
        3'b100: branch_flag = ($signed(in_a) < $signed(in_b)); // BLT
        3'b101: branch_flag = ($signed(in_a) >= $signed(in_b)); // BGE
        3'b110: branch_flag = (in_a < in_b); // BLTU
        3'b111: branch_flag = (in_a >= in_b); // BGEU
        default: branch_flag = 1'b0;
      endcase
   end

endmodule


// based on funct7[5] + funct3
module ALU (
            input [31:0]      in_a, in_b,
            input [3:0]       alu_control,
            output reg [31:0] alu_result,
            output reg        zero_flag
            );

   always @(*) begin
      case (alu_control)
        4'b0000: alu_result = in_a + in_b;  // ADD
        4'b1000: alu_result = in_a - in_b;  // SUB
        4'b0001: alu_result = in_a << in_b[4:0]; // SLL
        4'b0010: alu_result = ($signed(in_a) < $signed(in_b)) ? 32'b1 : 32'b0; // SLT
        4'b0011: alu_result = ($unsigned(in_a) < $unsigned(in_b)) ? 32'b1 : 32'b0; // SLTU
        4'b0100: alu_result = in_a ^ in_b; // XOR
        4'b0101: alu_result = in_a >> in_b[4:0]; // SRL
        4'b1101: alu_result = in_a >>> in_b[4:0]; // SRA
        4'b0110: alu_result = in_a | in_b; // OR
        4'b0111: alu_result = in_a & in_b; // AND
        4'b1111: alu_result = {in_b[19:0], 12'b0}; // LUI
        4'b1100: alu_result = in_a + ({in_b[19:0], 12'b0}); // AUIPC
        default: alu_result = 32'b0; // if the ALU is not being used
      endcase

      if (alu_result == 0)
        zero_flag = 1'b1;
      else
        zero_flag = 1'b0;

   end
endmodule // ALU

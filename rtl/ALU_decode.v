
module ALU_decode (
                   input            funct7b5,
                   input [2:0]      funct3,
                   input [6:0]      opcode,
                   output reg [3:0] alu_control
                   );

   localparam                       OP_LW = 7'b0000011;
   localparam                       OP_SW = 7'b0100011;
   localparam                       OP_R = 7'b0110011;
   localparam                       OP_B = 7'b1100011;
   localparam                       OP_I = 7'b0010011;
   localparam                       OP_J = 7'b1101111;

   always @(*) begin
      case(opcode)
        OP_I,
        OP_R: alu_control = {funct7b5, funct3};
        OP_LW: alu_control = 4'b0000; // add
        OP_SW: alu_control = 4'b0000; // add
        OP_B: alu_control = 4'b0000; // NOTE
        OP_J: alu_control = 4'b0000; // NOTE add
        default: alu_control = 4'b0000;
      endcase
   end

endmodule

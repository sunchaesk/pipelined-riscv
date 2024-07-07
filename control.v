module control (
                input [6:0]  opcode,
                input [2:0]  funct3,
                input        funct7b5,
                output       regwrite_d,
                output       memwrite_d,
                output       jump_d,
                output       branch_d,
                output       alu_src_d,
                output [1:0] result_src_d,
                output [3:0] alu_control_d
                );

   localparam OP_LW = 7'b0000011;
   localparam OP_SW = 7'b0100011;
   localparam OP_R = 7'b0110011;
   localparam OP_B = 7'b1100011;
   localparam OP_I = 7'b0010011;
   localparam OP_J = 7'b1101111;

   reg [6:0] control_signals;

   reg [1:0] result_src;
   reg       regwrite, memwrite, jump, branch, alu_src;

   ALU_decode ALU_decode_unit (
                               .funct3(funct3),
                               .funct7b5(funct7b5),
                               .opcode(opcode),
                               .alu_control(alu_control_d)
                               );

   always @(*) begin
      case (opcode)
         OP_LW: control_signals = 7'b1000100; // regwrite, alu_src, memwrite, result_src, branch, jump
         OP_SW: control_signals = 7'b0100000; // memwrite, alu_src
         OP_R:  control_signals = 7'b1000000; // regwrite
         OP_I:  control_signals = 7'b1100000; // regwrite, alu_src
         OP_B:  control_signals = 7'b0001000; // branch
         OP_J:  control_signals = 7'b1000010; // regwrite, result_src, jump
         default: control_signals = 7'b0000000; // default case to handle undefined opcodes
      endcase
   end

   assign {regwrite, alu_src, memwrite, result_src, branch, jump} = control_signals;

   assign regwrite_d = regwrite;
   assign memwrite_d = memwrite;
   assign jump_d = jump;
   assign branch_d = branch;
   assign alu_src_d = alu_src;
   assign result_src_d = result_src;

endmodule

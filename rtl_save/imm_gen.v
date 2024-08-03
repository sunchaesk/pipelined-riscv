
module imm_gen (
                input [31:0]      instruction,
                input [6:0]       opcode,
                output reg [31:0] immediate_out
                );

   localparam                     OP_LW = 7'b0000011;
   localparam                     OP_SW = 7'b0100011;
   // localparam                     OP_R  = 7'b0110011;
   localparam                     OP_B  = 7'b1100011;
   localparam                     OP_I  = 7'b0010011;
   localparam                     OP_J  = 7'b1101111;

   always @(*) begin
      case (opcode)
        OP_LW, OP_I: begin
           immediate_out = {{20{instruction[31]}}, instruction[31:20]};
        end
        OP_SW: begin
           immediate_out = {{20{instruction[31]}}, instruction[31:25], instruction[11:7]};
        end
        OP_B: begin
           immediate_out = {{20{instruction[31]}}, instruction[7], instruction[30:25], instruction[11:8], 1'b0};
        end
        OP_J: begin
           immediate_out = {{11{instruction[31]}}, instruction[31], instruction[19:12], instruction[20], instruction[30:25], instruction[24:21], 1'b0};
        end
        default: immediate_out = 32'b0;
      endcase
   end

endmodule

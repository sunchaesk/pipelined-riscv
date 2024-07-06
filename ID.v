
module ID (
           input             clk,
           input             reset,
           input [31:0]      instr,
           output [4:0]      rd,
           output reg [31:0] reg_a,
           output reg [31:0] reg_b,
           output reg [3:0]  alu_control,
           output reg [31:0] imm
           );

   reg [31:0]                reg_array [31:0]; // registers definition

   wire [4:0]                rs1;
   wire [4:0]                rs2;

   wire [6:0]                opcode;
   wire [2:0]                funct3;
   wire                      funct7b5;

   // intermediates
   wire [3:0]                alu_control_temp;
   wire [31:0]               immediate_generated_temp;


   // assigns
   assign rs1 = instr[19:15];
   assign rs2 = instr[24:20];

   assign funct3 = instr[14:12];
   assign funct7b5 = instr[30];


   //module inst
   ALU_decode ALU_decode_unit (
                               .funct3(funct3),
                               .funct7b5(funct7b5),
                               .opcode(opcode),
                               .alu_control(alu_control_temp)
                               );

   imm_gen immediate_generation_unit (
                                      .instruction(instr),
                                      .opcode(opcode),
                                      .immediate_out(immediate_generated_temp)
                                      );

   always @(posedge clk or posedge reset) begin
      if (reset) begin
         reg_a <= 32'b0;
         reg_b <= 32'b0;
         alu_control <= 4'b0;
         imm <= 32'b0;
      end else begin
         reg_a <= reg_array[rs1];
         reg_b <= reg_array[rs2];
         alu_control <= alu_control_temp;
         imm <= immediate_generated_temp;
      end
   end
endmodule

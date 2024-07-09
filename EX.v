
// pass -> refers to just passing the value to the forward
module EX (
           input             clk,
           input             reset,
           // control signals
           input             regwrite_e,
           input [1:0]       result_src_e,
           input             memwrite_e,
           input             jump_e,
           input             branch_e,
           input [3:0]       alu_control_e,
           input [2:0]       branch_control_e,
           input             alu_src_e,
           // other
           input [31:0]      rs1_data_e,
           input [31:0]      rs2_data_e,
           input [31:0]      pc_e,
           input [31:0]      pc_plus_4_e,
           input [4:0]       rd_e,
           input [31:0]      immediate_e,
           // output
           output             zero_flag,
           output             branch_flag,
           output             pc_src_e,
           output reg [31:0]     pc_target_e,
           output reg [31:0] alu_result,
           output reg [31:0] writedata,
           // forward
           output reg [31:0] ex_mem_pc_plus_4_e,
           output reg [4:0]  ex_mem_rd,
           output reg        ex_mem_regwrite_e,
           output reg [1:0]  ex_mem_result_src_e,
           output reg        ex_mem_memwrite_e
           );

   // intermediate alu values
   wire [31:0]               operand_a;
   wire [31:0]               operand_b;

   wire [31:0]               alu_result_temp;


   assign pc_src_e = (branch_flag & branch_e) | jump_e;

   // assign statements
   assign operand_a = rs1_data_e;
   assign operand_b = alu_src_e ? immediate_e : rs2_data_e;

   assign pc_target_e = pc_e + immediate_e;


   ALU ALU_unit (
                 .in_a(operand_a),
                 .in_b(operand_b),
                 .alu_control(alu_control_e),
                 .alu_result(alu_result_temp),
                 .zero_flag(zero_flag)
                 );

   branch_condition branch_condition_unit (
                                           .in_a(operand_a),
                                           .in_b(operand_b),
                                           .branch_control(branch_control_e),
                                           .branch_flag(branch_flag)
                                           );


   // pipeline registers
   always @(posedge clk or posedge reset) begin
      if (reset) begin
         //forward
         ex_mem_pc_plus_4_e <= 32'b0;
         ex_mem_rd <= 5'b0;
         ex_mem_regwrite_e <= 1'b0;
         ex_mem_result_src_e <= 2'b0;
         ex_mem_memwrite_e <= 1'b0;
         alu_result <= 32'b0;
         writedata <= 32'b0;

      end else begin
         //forward
         ex_mem_pc_plus_4_e <= pc_plus_4_e;
         ex_mem_rd <= rd_e;
         ex_mem_regwrite_e <= regwrite_e;
         ex_mem_result_src_e <= result_src_e;
         ex_mem_memwrite_e <= memwrite_e;
         alu_result <= alu_result_temp;
         writedata <= rs2_data_e;

      end
   end

endmodule

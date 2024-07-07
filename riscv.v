module riscv (
              input         clk,
              input         reset,
              output [31:0] instr_out,
              output [31:0] pc_out
              );

   // control signals
   wire                     pc_src;

   /////// pipelining registers
   // IF/ID
   wire [31:0]               if_id_instr;
   wire [31:0]               if_id_pc;
   wire [31:0]               if_id_pc_plus_4;
   //ID/EX
   wire [4:0]                id_ex_rd;
   wire [31:0]               id_ex_pc;
   wire [31:0]               id_ex_reg_a;
   wire [31:0]               id_ex_reg_b;
   wire [31:0]               id_ex_imm;
   wire                      id_ex_regwrite_d;
   wire [1:0]                id_ex_result_src_d;
   wire                      id_ex_memwrite_d;
   wire                      id_ex_jump_d;
   wire                      id_ex_branch_d;
   wire [3:0]                id_ex_alu_control_d;
   wire                      id_ex_alu_src_d;
   wire [31:0]               id_ex_pc_plus_4;
   //ex mem
   wire [31:0]               ex_mem_alu_result;
   wire [31:0]               ex_mem_reg_b;
   wire [31:0]               ex_mem_instr;
   // mem wb
   wire [31:0]               mem_wb_alu_result;
   wire [31:0]               mem_wb_instr;
   wire [31:0]               mem_wb_data;

   //////// wire def
   wire [31:0]              alu_result;
   wire                     zero_flag;

   // instantiate stages
   IF IF_unit (
               .clk(clk),
               .reset(reset),
               .pc_src(pc_src),
               .pc_branch_dest(32'hA),
               // output start
               .pc(if_id_pc),
               .pc_plus_4(if_id_pc_plus_4),
               .instruction(if_id_instr)
               );

   ID ID_unit (
               .clk(clk),
               .reset(reset),
               .writeback_control(1'b0), // TODO
               .instruction(if_id_instr),
               .pc_plus_4(if_id_pc_plus_4),
               .writeback_data(32'b0), // TODO
               // output start
               .immediate(id_ex_imm),
               .rs1_data(id_ex_reg_a),
               .rs2_data(id_ex_reg_b),
               .rd_out(id_ex_rd),
               // output control signals
               .regwrite_d(id_ex_regwrite_d),
               .result_src_d(id_ex_result_src_d),
               .memwrite_d(id_ex_memwrite_d),
               .jump_d(id_ex_jump_d),
               .branch_d(id_ex_branch_d),
               .alu_control_d(id_ex_alu_control_d),
               .alu_src_d(id_ex_alu_src_d),
               .id_ex_pc_plus_4(id_ex_pc_plus_4)
               );


   // // Connect outputs
   // assign instr_out = if_id_instr;
   // assign pc_out = if_id_pc;

endmodule

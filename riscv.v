module riscv (
              input         clk,
              input         reset,
              output [31:0] instr_out,
              output [31:0] pc_out
              );

   // control signals
   // wire                     pc_src;

   /////// pipelining registers
   // IF/ID
   wire [31:0]               if_id_instr;
   wire [31:0]               if_id_pc;
   wire [31:0]               if_id_pc_plus_4;
   //ID/EX
   wire [4:0]                id_ex_rd;
   wire [31:0]               id_ex_pc;
   wire [31:0]               id_ex_reg_a; // rs1_data
   wire [31:0]               id_ex_reg_b; // rs2_data
   wire [31:0]               id_ex_imm;
   wire                      id_ex_regwrite_d;
   wire [1:0]                id_ex_result_src_d;
   wire                      id_ex_memwrite_d;
   wire                      id_ex_jump_d;
   wire                      id_ex_branch_d;
   wire [3:0]                id_ex_alu_control_d;
   wire [2:0]                id_ex_branch_control_d;
   wire                      id_ex_alu_src_d;
   wire [31:0]               id_ex_pc_plus_4; // forward
   wire [31:0]               id_ex_pc; // forward

   //ex mem
   wire                      ex_mem_zero_flag_e;
   wire                      ex_mem_branch_flag_e;
   wire [31:0]               ex_mem_pc_target_e;
   wire [31:0]               ex_mem_alu_result_e;
   wire [31:0]               ex_mem_writedata_e;
   wire [31:0]               ex_mem_pc_plus_4_e;
   wire [4:0]                ex_mem_rd_e;
   wire                      ex_mem_regwrite_e;
   wire [1:0]                ex_mem_result_src_e;
   wire                      ex_mem_memwrite_e;
   wire                      ex_mem_pc_src_e;


   // mem wb
   wire [31:0]               mem_wb_readdata_w;
   wire                      mem_wb_regwrite_w;
   wire [1:0]                mem_wb_result_src_w;
   wire [31:0]               mem_wb_alu_result_w;
   wire [31:00]              mem_wb_pc_plus_4_w;
   wire [4:0]                mem_wb_rd_w;

   // wb stuff
   wire                      wb_regwrite;
   wire [4:0]                wb_rd;
   wire [31:0]               wb_result;

   //////// wire def
   wire [31:0]              alu_result;
   wire                     zero_flag;

   // instantiate stages
   IF IF_unit (
               .clk(clk),
               .reset(reset),
               .pc_src(ex_mem_pc_src_e),
               .pc_branch_dest(ex_mem_pc_target_e),
               // output start
               .pc(if_id_pc),
               .pc_plus_4(if_id_pc_plus_4),
               .instruction(if_id_instr)
               );

   ID ID_unit (
               .clk(clk),
               .reset(reset),
               .writeback_control(wb_regwrite), // TODO
               .rd(wb_rd),
               .instruction(if_id_instr),
               .pc(if_id_pc),
               .pc_plus_4(if_id_pc_plus_4),
               .writeback_data(wb_result), // TODO
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
               .branch_control_d(id_ex_branch_control_d),
               .alu_src_d(id_ex_alu_src_d),
               .id_ex_pc_plus_4(id_ex_pc_plus_4),
               .id_ex_pc(id_ex_pc)
               );

   EX EX_unit (
               .clk(clk),
               .reset(reset),
               .regwrite_e(id_ex_regwrite_d),
               .result_src_e(id_ex_result_src_d),
               .memwrite_e(id_ex_memwrite_d),
               .jump_e(id_ex_jump_d),
               .branch_e(id_ex_branch_d),
               .alu_control_e(id_ex_alu_control_d),
               .branch_control_e(id_ex_branch_control_d),
               .alu_src_e(id_ex_alu_src_d),
               .rs1_data_e(id_ex_reg_a),
               .rs2_data_e(id_ex_reg_b),
               .pc_e(id_ex_pc),
               .pc_plus_4_e(id_ex_pc_plus_4),
               .rd_e(id_ex_rd),
               .immediate_e(id_ex_imm),
               // output start
               .zero_flag(ex_mem_zero_flag_e),
               .branch_flag(ex_mem_branch_flag_e),
               .pc_src_e(ex_mem_pc_src_e),
               .pc_target_e(ex_mem_pc_target_e),
               .alu_result(ex_mem_alu_result_e),
               .writedata(ex_mem_writedata_e),
               .ex_mem_pc_plus_4_e(ex_mem_pc_plus_4_e),
               .ex_mem_rd(ex_mem_rd_e),
               .ex_mem_regwrite_e(ex_mem_regwrite_e),
               .ex_mem_result_src_e(ex_mem_result_src_e),
               .ex_mem_memwrite_e(ex_mem_memwrite_e)
               );

   MEM MEM_unit (
                 .clk(clk),
                 .reset(reset),
                 .regwrite_m(ex_mem_regwrite_e),
                 .result_src_m(ex_mem_result_src_e),
                 .memwrite_m(ex_mem_memwrite_e),
                 .alu_result_m(ex_mem_alu_result_e),
                 .writedata_m(ex_mem_writedata_e),
                 .rd_m(ex_mem_rd_e),
                 .pc_plus_4_m(ex_mem_pc_plus_4_e),
                 // output
                 .readdata(mem_wb_readdata_w),
                 .mem_wb_regwrite(mem_wb_regwrite_w),
                 .mem_wb_result_src(mem_wb_result_src_w),
                 .mem_wb_alu_result(mem_wb_alu_result_w),
                 .mem_wb_pc_plus_4(mem_wb_pc_plus_4_w),
                 .mem_wb_rd(mem_wb_rd_w)
                 );

   WB WB_unit (
               .clk(clk),
               .reset(reset),
               .regwrite_w(mem_wb_regwrite_w),
               .result_src_w(mem_wb_result_src_w),
               .alu_result_w(mem_wb_alu_result_w),
               .readdata_w(mem_wb_readdata_w),
               .rd_w(mem_wb_rd_w),
               .pc_plus_4_w(mem_wb_pc_plus_4_w),
               // output
               .wb_regwrite(wb_regwrite),
               .wb_rd(wb_rd),
               .wb_result(wb_result)
               );



   // // Connect outputs
   // assign instr_out = if_id_instr;
   // assign pc_out = if_id_pc;

endmodule

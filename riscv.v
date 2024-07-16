module riscv (
              input         clk,
              input         reset
              // output [31:0] instr_out,
              // output [31:0] pc_out
              );

   // control signals
   // wire                     pc_src;

   /////// pipelining registers
   // IF/ID
   wire [31:0]              if_id_instr;
   wire [31:0]              if_id_pc;
   wire [31:0]              if_id_pc_plus_4;
   //ID/EX
   wire [4:0]               id_ex_rd;
   wire [31:0]              id_ex_pc;
   wire [31:0]              id_ex_reg_a; // rs1_data
   wire [31:0]              id_ex_reg_b; // rs2_data
   wire [31:0]              id_ex_imm;
   wire                     id_ex_regwrite_d;
   wire [1:0]               id_ex_result_src_d;
   wire [1:0]               id_ex_result_src_d_wire;
   wire                     id_ex_memwrite_d;
   wire                     id_ex_jump_d;
   wire                     id_ex_branch_d;
   wire [3:0]               id_ex_alu_control_d;
   wire [2:0]               id_ex_branch_control_d;
   wire                     id_ex_alu_src_d;
   wire [31:0]              id_ex_pc_plus_4; // forward
   wire [31:0]              id_ex_pc; // forward
   wire [4:0]               id_ex_rs1_d_wire; // hazard
   wire [4:0]               id_ex_rs2_d_wire; // hazard
   wire [4:0]               id_ex_rs1_d_reg; // hazard
   wire [4:0]               id_ex_rs2_d_reg; // hazard

   //ex mem
   wire                     ex_mem_zero_flag_e;
   wire                     ex_mem_branch_flag_e;
   wire [31:0]              ex_mem_pc_target_e;
   wire [31:0]              ex_mem_alu_result_e;
   wire [31:0]              ex_mem_writedata_e;
   wire [31:0]              ex_mem_pc_plus_4_e;
   wire [4:0]               ex_mem_rd_e;
   wire                     ex_mem_regwrite_e;
   wire [1:0]               ex_mem_result_src_e;
   wire                     ex_mem_memwrite_e;
   wire                     ex_mem_pc_src_e;
   wire [4:0]               ex_rs1_e; //hazard
   wire [4:0]               ex_rs2_e; // hazard
   wire [4:0]               ex_rd_e; //hazard
   // wire [4:0]               ex_rs1_e_reg; //hazard
   // wire [4:0]               ex_rs2_e_reg; // hazard
   // wire [4:0]               ex_rd_e_reg; //hazard




   // mem wb NOTE: naming convention little off, postfix should be _m
   wire [31:0]              mem_wb_readdata_w;
   wire                     mem_wb_regwrite_w;
   wire [1:0]               mem_wb_result_src_w;
   wire [31:0]              mem_wb_alu_result_w;
   wire [31:0]             mem_wb_pc_plus_4_w;
   wire [4:0]               mem_wb_rd_w;
   wire                     mem_regwrite_m;
   wire [31:0]              mem_alu_result_m;
   wire [31:0]              mem_wb_result;

   // wb stuff
   wire                     wb_regwrite;
   wire [4:0]               wb_rd;
   wire [31:0]              wb_result;

   //////// wire def
   wire [31:0]              alu_result;
   wire                     zero_flag;

   // hazard unit
   wire                     stall_f;
   wire                     stall_d;
   wire                     flush_d;
   wire                     flush_e;
   wire [1:0]               forward_operand_a_e;
   wire [1:0]               forward_operand_b_e;

   // instantiate stages
   IF IF_unit (
               .clk(clk),
               .reset(reset),
               .pc_src(ex_mem_pc_src_e),
               .stall_f(stall_f),
               .pc_branch_dest(ex_mem_pc_target_e),
               // output start
               .pc(if_id_pc),
               .pc_plus_4(if_id_pc_plus_4),
               .instruction(if_id_instr)
               );

   ID ID_unit (
               .clk(clk),
               .reset(reset),
               .writeback_control(wb_regwrite),
               .rd(wb_rd),
               .instruction(if_id_instr),
               .pc(if_id_pc),
               .pc_plus_4(if_id_pc_plus_4),
               .writeback_data(wb_result),
               .stall_d(stall_d),
               .flush_d(flush_d),
               // output start
               .immediate(id_ex_imm),
               .rs1_data(id_ex_reg_a),
               .rs2_data(id_ex_reg_b),
               .rd_out(id_ex_rd),
               // output control signals
               .regwrite_d(id_ex_regwrite_d),
               .result_src_d(id_ex_result_src_d),
               .result_src_d_wire(id_ex_result_src_d_wire),
               .memwrite_d(id_ex_memwrite_d),
               .jump_d(id_ex_jump_d),
               .branch_d(id_ex_branch_d),
               .alu_control_d(id_ex_alu_control_d),
               .branch_control_d(id_ex_branch_control_d),
               .alu_src_d(id_ex_alu_src_d),
               .id_ex_pc_plus_4(id_ex_pc_plus_4),
               .id_ex_pc(id_ex_pc),
               // forward
               .id_ex_rs1_d_wire(id_ex_rs1_d_wire),
               .id_ex_rs2_d_wire(id_ex_rs2_d_wire),

               .id_ex_rs1_d_reg(id_ex_rs1_d_reg),
               .id_ex_rs2_d_reg(id_ex_rs2_d_reg)
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
               //hazard start input
               .rs1_e(id_ex_rs1_d_reg),
               .rs2_e(id_ex_rs2_d_reg),
               .alu_result_m(mem_alu_result_m),
               // .result_w(wb_result), // NOTE
               // .result_w(mem_wb_alu_result_w), // NOTE: trying it out
               .result_w(mem_wb_result), // TODO
               // hazard end
               .rd_e(id_ex_rd),
               .immediate_e(id_ex_imm),
               .flush_e(flush_e),
               .forward_operand_a_e(forward_operand_a_e),
               .forward_operand_b_e(forward_operand_b_e),
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
               .ex_mem_memwrite_e(ex_mem_memwrite_e),
               // hazard output
               .ex_rs1_e(ex_rs1_e),
               .ex_rs2_e(ex_rs2_e),
               .ex_rd_e(ex_rd_e)
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
                 .mem_wb_rd(mem_wb_rd_w),
                 .mem_regwrite_m(mem_regwrite_m),
                 .mem_alu_result_m(mem_alu_result_m)
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
               .wb_result(wb_result),
               .mem_wb_result(mem_wb_result)
               );



   hazard hazard_unit (
                       .clk(clk),
                       .reset(reset),
                       .rs1_d(id_ex_rs1_d_wire),
                       .rs2_d(id_ex_rs2_d_wire),
                       .pc_src_e(ex_mem_pc_src_e),
                       .rs1_e(ex_rs1_e), // NOTE
                       .rs2_e(ex_rs2_e), // NOTE
                       .rd_e(ex_rd_e),
                       .result_src_e_0(id_ex_result_src_d[0]),
                       .regwrite_w(mem_wb_regwrite_w),
                       .rd_m(ex_mem_rd_e),
                       // .rd_w(wb_rd),
                       .rd_w(mem_wb_rd_w),
                       .regwrite_m(mem_regwrite_m),
                       //.alu_result_m(mem_alu_result_m),
                       //output
                       .stall_f(stall_f),
                       .stall_d(stall_d),
                       .flush_d(flush_d),
                       .flush_e(flush_e),
                       .forward_operand_a_e(forward_operand_a_e),
                       .forward_operand_b_e(forward_operand_b_e)
                       );


   // // Connect outputs
     // assign instr_out = if_id_instr;
   // assign pc_out = if_id_pc;

endmodule

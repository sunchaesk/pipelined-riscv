
module riscv (
              input         clk,
              input         reset,
              output [31:0] pc_out
              );

   // pc and instruction reg
   reg [31:0]               pc;
   reg [31:0]               instruction;

   // pipelining registers
   reg [31:0]               if_id_instr;
   reg [31:0]               if_id_pc;

   reg [31:0]               id_ex_instr;
   reg [31:0]               id_ex_pc;
   reg [31:0]               id_ex_reg_a;
   reg [31:0]               id_ex_reg_b;
   reg [31:0]               id_ex_alu_control;

   reg [31:0]               ex_mem_alu_result;
   reg [31:0]               ex_mem_reg_b;
   reg [31:0]               ex_mem_instr;

   reg [31:0]               mem_wb_alu_result;
   reg [31:0]               mem_wb_instr;
   reg [31:0]               mem_wb_data;

   wire [31:0]              alu_result;
   wire                     zero_flag;


endmodule

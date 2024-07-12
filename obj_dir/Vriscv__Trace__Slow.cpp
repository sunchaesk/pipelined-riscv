// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vriscv__Syms.h"


//======================

void Vriscv::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vriscv::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vriscv__Syms* __restrict vlSymsp = static_cast<Vriscv__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vriscv::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vriscv::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vriscv__Syms* __restrict vlSymsp = static_cast<Vriscv__Syms*>(userp);
    Vriscv* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vriscv::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vriscv__Syms* __restrict vlSymsp = static_cast<Vriscv__Syms*>(userp);
    Vriscv* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+128,"clk", false,-1);
        tracep->declBit(c+129,"reset", false,-1);
        tracep->declBit(c+128,"riscv clk", false,-1);
        tracep->declBit(c+129,"riscv reset", false,-1);
        tracep->declBus(c+46,"riscv if_id_instr", false,-1, 31,0);
        tracep->declBus(c+47,"riscv if_id_pc", false,-1, 31,0);
        tracep->declBus(c+48,"riscv if_id_pc_plus_4", false,-1, 31,0);
        tracep->declBus(c+49,"riscv id_ex_rd", false,-1, 4,0);
        tracep->declBus(c+50,"riscv id_ex_pc", false,-1, 31,0);
        tracep->declBus(c+1,"riscv id_ex_reg_a", false,-1, 31,0);
        tracep->declBus(c+2,"riscv id_ex_reg_b", false,-1, 31,0);
        tracep->declBus(c+51,"riscv id_ex_imm", false,-1, 31,0);
        tracep->declBit(c+52,"riscv id_ex_regwrite_d", false,-1);
        tracep->declBus(c+53,"riscv id_ex_result_src_d", false,-1, 1,0);
        tracep->declBit(c+3,"riscv id_ex_memwrite_d", false,-1);
        tracep->declBit(c+4,"riscv id_ex_jump_d", false,-1);
        tracep->declBit(c+5,"riscv id_ex_branch_d", false,-1);
        tracep->declBus(c+6,"riscv id_ex_alu_control_d", false,-1, 3,0);
        tracep->declBus(c+7,"riscv id_ex_branch_control_d", false,-1, 2,0);
        tracep->declBit(c+8,"riscv id_ex_alu_src_d", false,-1);
        tracep->declBus(c+54,"riscv id_ex_pc_plus_4", false,-1, 31,0);
        tracep->declBus(c+55,"riscv id_ex_rs1_d_wire", false,-1, 4,0);
        tracep->declBus(c+56,"riscv id_ex_rs2_d_wire", false,-1, 4,0);
        tracep->declBus(c+9,"riscv id_ex_rs1_d_reg", false,-1, 4,0);
        tracep->declBus(c+10,"riscv id_ex_rs2_d_reg", false,-1, 4,0);
        tracep->declBit(c+57,"riscv ex_mem_zero_flag_e", false,-1);
        tracep->declBit(c+130,"riscv ex_mem_branch_flag_e", false,-1);
        tracep->declBus(c+58,"riscv ex_mem_pc_target_e", false,-1, 31,0);
        tracep->declBus(c+59,"riscv ex_mem_alu_result_e", false,-1, 31,0);
        tracep->declBus(c+11,"riscv ex_mem_writedata_e", false,-1, 31,0);
        tracep->declBus(c+60,"riscv ex_mem_pc_plus_4_e", false,-1, 31,0);
        tracep->declBus(c+61,"riscv ex_mem_rd_e", false,-1, 4,0);
        tracep->declBit(c+62,"riscv ex_mem_regwrite_e", false,-1);
        tracep->declBus(c+63,"riscv ex_mem_result_src_e", false,-1, 1,0);
        tracep->declBit(c+12,"riscv ex_mem_memwrite_e", false,-1);
        tracep->declBit(c+64,"riscv ex_mem_pc_src_e", false,-1);
        tracep->declBus(c+9,"riscv ex_rs1_e", false,-1, 4,0);
        tracep->declBus(c+10,"riscv ex_rs2_e", false,-1, 4,0);
        tracep->declBus(c+49,"riscv ex_rd_e", false,-1, 4,0);
        tracep->declBus(c+65,"riscv mem_wb_readdata_w", false,-1, 31,0);
        tracep->declBit(c+66,"riscv mem_wb_regwrite_w", false,-1);
        tracep->declBus(c+67,"riscv mem_wb_result_src_w", false,-1, 1,0);
        tracep->declBus(c+68,"riscv mem_wb_alu_result_w", false,-1, 31,0);
        tracep->declBus(c+69,"riscv mem_wb_pc_plus_4_w", false,-1, 31,0);
        tracep->declBus(c+70,"riscv mem_wb_rd_w", false,-1, 4,0);
        tracep->declBit(c+62,"riscv mem_regwrite_m", false,-1);
        tracep->declBus(c+59,"riscv mem_alu_result_m", false,-1, 31,0);
        tracep->declBit(c+71,"riscv wb_regwrite", false,-1);
        tracep->declBus(c+72,"riscv wb_rd", false,-1, 4,0);
        tracep->declBus(c+73,"riscv wb_result", false,-1, 31,0);
        tracep->declBus(c+132,"riscv alu_result", false,-1, 31,0);
        tracep->declBit(c+133,"riscv zero_flag", false,-1);
        tracep->declBit(c+74,"riscv stall_f", false,-1);
        tracep->declBit(c+74,"riscv stall_d", false,-1);
        tracep->declBit(c+75,"riscv flush_d", false,-1);
        tracep->declBit(c+76,"riscv flush_e", false,-1);
        tracep->declBus(c+77,"riscv forward_operand_a_e", false,-1, 1,0);
        tracep->declBus(c+78,"riscv forward_operand_b_e", false,-1, 1,0);
        tracep->declBit(c+128,"riscv IF_unit clk", false,-1);
        tracep->declBit(c+129,"riscv IF_unit reset", false,-1);
        tracep->declBit(c+64,"riscv IF_unit pc_src", false,-1);
        tracep->declBit(c+74,"riscv IF_unit stall_f", false,-1);
        tracep->declBus(c+58,"riscv IF_unit pc_branch_dest", false,-1, 31,0);
        tracep->declBus(c+47,"riscv IF_unit pc", false,-1, 31,0);
        tracep->declBus(c+48,"riscv IF_unit pc_plus_4", false,-1, 31,0);
        tracep->declBus(c+46,"riscv IF_unit instruction", false,-1, 31,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declBus(c+134+i*1,"riscv IF_unit instr_mem", true,(i+0), 31,0);}}
        tracep->declBus(c+79,"riscv IF_unit next_pc", false,-1, 31,0);
        tracep->declBit(c+128,"riscv ID_unit clk", false,-1);
        tracep->declBit(c+129,"riscv ID_unit reset", false,-1);
        tracep->declBit(c+71,"riscv ID_unit writeback_control", false,-1);
        tracep->declBus(c+72,"riscv ID_unit rd", false,-1, 4,0);
        tracep->declBus(c+46,"riscv ID_unit instruction", false,-1, 31,0);
        tracep->declBus(c+47,"riscv ID_unit pc", false,-1, 31,0);
        tracep->declBus(c+48,"riscv ID_unit pc_plus_4", false,-1, 31,0);
        tracep->declBus(c+73,"riscv ID_unit writeback_data", false,-1, 31,0);
        tracep->declBit(c+74,"riscv ID_unit stall_d", false,-1);
        tracep->declBit(c+75,"riscv ID_unit flush_d", false,-1);
        tracep->declBus(c+51,"riscv ID_unit immediate", false,-1, 31,0);
        tracep->declBus(c+1,"riscv ID_unit rs1_data", false,-1, 31,0);
        tracep->declBus(c+2,"riscv ID_unit rs2_data", false,-1, 31,0);
        tracep->declBus(c+49,"riscv ID_unit rd_out", false,-1, 4,0);
        tracep->declBit(c+52,"riscv ID_unit regwrite_d", false,-1);
        tracep->declBus(c+53,"riscv ID_unit result_src_d", false,-1, 1,0);
        tracep->declBit(c+3,"riscv ID_unit memwrite_d", false,-1);
        tracep->declBit(c+4,"riscv ID_unit jump_d", false,-1);
        tracep->declBit(c+5,"riscv ID_unit branch_d", false,-1);
        tracep->declBus(c+6,"riscv ID_unit alu_control_d", false,-1, 3,0);
        tracep->declBus(c+7,"riscv ID_unit branch_control_d", false,-1, 2,0);
        tracep->declBit(c+8,"riscv ID_unit alu_src_d", false,-1);
        tracep->declBus(c+54,"riscv ID_unit id_ex_pc_plus_4", false,-1, 31,0);
        tracep->declBus(c+50,"riscv ID_unit id_ex_pc", false,-1, 31,0);
        tracep->declBus(c+55,"riscv ID_unit id_ex_rs1_d_wire", false,-1, 4,0);
        tracep->declBus(c+56,"riscv ID_unit id_ex_rs2_d_wire", false,-1, 4,0);
        tracep->declBus(c+9,"riscv ID_unit id_ex_rs1_d_reg", false,-1, 4,0);
        tracep->declBus(c+10,"riscv ID_unit id_ex_rs2_d_reg", false,-1, 4,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declBus(c+13+i*1,"riscv ID_unit reg_array", true,(i+0), 31,0);}}
        tracep->declBus(c+55,"riscv ID_unit rs1", false,-1, 4,0);
        tracep->declBus(c+56,"riscv ID_unit rs2", false,-1, 4,0);
        tracep->declBus(c+80,"riscv ID_unit opcode", false,-1, 6,0);
        tracep->declBus(c+81,"riscv ID_unit funct3", false,-1, 2,0);
        tracep->declBit(c+82,"riscv ID_unit funct7b5", false,-1);
        tracep->declBus(c+83,"riscv ID_unit immediate_temp", false,-1, 31,0);
        tracep->declBit(c+84,"riscv ID_unit regwrite_d_temp", false,-1);
        tracep->declBit(c+85,"riscv ID_unit memwrite_d_temp", false,-1);
        tracep->declBit(c+86,"riscv ID_unit jump_d_temp", false,-1);
        tracep->declBit(c+87,"riscv ID_unit branch_d_temp", false,-1);
        tracep->declBit(c+88,"riscv ID_unit alu_src_d_temp", false,-1);
        tracep->declBus(c+89,"riscv ID_unit alu_control_d_temp", false,-1, 3,0);
        tracep->declBus(c+81,"riscv ID_unit branch_control_d_temp", false,-1, 2,0);
        tracep->declBus(c+90,"riscv ID_unit result_src_d_temp", false,-1, 1,0);
        tracep->declBus(c+45,"riscv ID_unit i", false,-1, 31,0);
        tracep->declBus(c+46,"riscv ID_unit immediate_generation_unit instruction", false,-1, 31,0);
        tracep->declBus(c+80,"riscv ID_unit immediate_generation_unit opcode", false,-1, 6,0);
        tracep->declBus(c+83,"riscv ID_unit immediate_generation_unit immediate_out", false,-1, 31,0);
        tracep->declBus(c+166,"riscv ID_unit immediate_generation_unit OP_LW", false,-1, 6,0);
        tracep->declBus(c+167,"riscv ID_unit immediate_generation_unit OP_SW", false,-1, 6,0);
        tracep->declBus(c+168,"riscv ID_unit immediate_generation_unit OP_B", false,-1, 6,0);
        tracep->declBus(c+169,"riscv ID_unit immediate_generation_unit OP_I", false,-1, 6,0);
        tracep->declBus(c+170,"riscv ID_unit immediate_generation_unit OP_J", false,-1, 6,0);
        tracep->declBus(c+80,"riscv ID_unit control_signal_unit opcode", false,-1, 6,0);
        tracep->declBus(c+81,"riscv ID_unit control_signal_unit funct3", false,-1, 2,0);
        tracep->declBit(c+82,"riscv ID_unit control_signal_unit funct7b5", false,-1);
        tracep->declBit(c+84,"riscv ID_unit control_signal_unit regwrite_d", false,-1);
        tracep->declBit(c+85,"riscv ID_unit control_signal_unit memwrite_d", false,-1);
        tracep->declBit(c+86,"riscv ID_unit control_signal_unit jump_d", false,-1);
        tracep->declBit(c+87,"riscv ID_unit control_signal_unit branch_d", false,-1);
        tracep->declBit(c+88,"riscv ID_unit control_signal_unit alu_src_d", false,-1);
        tracep->declBus(c+90,"riscv ID_unit control_signal_unit result_src_d", false,-1, 1,0);
        tracep->declBus(c+89,"riscv ID_unit control_signal_unit alu_control_d", false,-1, 3,0);
        tracep->declBus(c+81,"riscv ID_unit control_signal_unit branch_control_d", false,-1, 2,0);
        tracep->declBus(c+166,"riscv ID_unit control_signal_unit OP_LW", false,-1, 6,0);
        tracep->declBus(c+167,"riscv ID_unit control_signal_unit OP_SW", false,-1, 6,0);
        tracep->declBus(c+171,"riscv ID_unit control_signal_unit OP_R", false,-1, 6,0);
        tracep->declBus(c+168,"riscv ID_unit control_signal_unit OP_B", false,-1, 6,0);
        tracep->declBus(c+169,"riscv ID_unit control_signal_unit OP_I", false,-1, 6,0);
        tracep->declBus(c+170,"riscv ID_unit control_signal_unit OP_J", false,-1, 6,0);
        tracep->declBus(c+91,"riscv ID_unit control_signal_unit control_signals", false,-1, 6,0);
        tracep->declBus(c+90,"riscv ID_unit control_signal_unit result_src", false,-1, 1,0);
        tracep->declBit(c+84,"riscv ID_unit control_signal_unit regwrite", false,-1);
        tracep->declBit(c+85,"riscv ID_unit control_signal_unit memwrite", false,-1);
        tracep->declBit(c+86,"riscv ID_unit control_signal_unit jump", false,-1);
        tracep->declBit(c+87,"riscv ID_unit control_signal_unit branch", false,-1);
        tracep->declBit(c+88,"riscv ID_unit control_signal_unit alu_src", false,-1);
        tracep->declBit(c+82,"riscv ID_unit control_signal_unit ALU_decode_unit funct7b5", false,-1);
        tracep->declBus(c+81,"riscv ID_unit control_signal_unit ALU_decode_unit funct3", false,-1, 2,0);
        tracep->declBus(c+80,"riscv ID_unit control_signal_unit ALU_decode_unit opcode", false,-1, 6,0);
        tracep->declBus(c+89,"riscv ID_unit control_signal_unit ALU_decode_unit alu_control", false,-1, 3,0);
        tracep->declBus(c+166,"riscv ID_unit control_signal_unit ALU_decode_unit OP_LW", false,-1, 6,0);
        tracep->declBus(c+167,"riscv ID_unit control_signal_unit ALU_decode_unit OP_SW", false,-1, 6,0);
        tracep->declBus(c+171,"riscv ID_unit control_signal_unit ALU_decode_unit OP_R", false,-1, 6,0);
        tracep->declBus(c+168,"riscv ID_unit control_signal_unit ALU_decode_unit OP_B", false,-1, 6,0);
        tracep->declBus(c+169,"riscv ID_unit control_signal_unit ALU_decode_unit OP_I", false,-1, 6,0);
        tracep->declBus(c+170,"riscv ID_unit control_signal_unit ALU_decode_unit OP_J", false,-1, 6,0);
        tracep->declBit(c+128,"riscv EX_unit clk", false,-1);
        tracep->declBit(c+129,"riscv EX_unit reset", false,-1);
        tracep->declBit(c+52,"riscv EX_unit regwrite_e", false,-1);
        tracep->declBus(c+53,"riscv EX_unit result_src_e", false,-1, 1,0);
        tracep->declBit(c+3,"riscv EX_unit memwrite_e", false,-1);
        tracep->declBit(c+4,"riscv EX_unit jump_e", false,-1);
        tracep->declBit(c+5,"riscv EX_unit branch_e", false,-1);
        tracep->declBus(c+6,"riscv EX_unit alu_control_e", false,-1, 3,0);
        tracep->declBus(c+7,"riscv EX_unit branch_control_e", false,-1, 2,0);
        tracep->declBit(c+8,"riscv EX_unit alu_src_e", false,-1);
        tracep->declBus(c+1,"riscv EX_unit rs1_data_e", false,-1, 31,0);
        tracep->declBus(c+2,"riscv EX_unit rs2_data_e", false,-1, 31,0);
        tracep->declBus(c+50,"riscv EX_unit pc_e", false,-1, 31,0);
        tracep->declBus(c+54,"riscv EX_unit pc_plus_4_e", false,-1, 31,0);
        tracep->declBus(c+9,"riscv EX_unit rs1_e", false,-1, 4,0);
        tracep->declBus(c+10,"riscv EX_unit rs2_e", false,-1, 4,0);
        tracep->declBus(c+59,"riscv EX_unit alu_result_m", false,-1, 31,0);
        tracep->declBus(c+68,"riscv EX_unit result_w", false,-1, 31,0);
        tracep->declBus(c+49,"riscv EX_unit rd_e", false,-1, 4,0);
        tracep->declBus(c+51,"riscv EX_unit immediate_e", false,-1, 31,0);
        tracep->declBit(c+76,"riscv EX_unit flush_e", false,-1);
        tracep->declBus(c+77,"riscv EX_unit forward_operand_a_e", false,-1, 1,0);
        tracep->declBus(c+78,"riscv EX_unit forward_operand_b_e", false,-1, 1,0);
        tracep->declBit(c+57,"riscv EX_unit zero_flag", false,-1);
        tracep->declBit(c+130,"riscv EX_unit branch_flag", false,-1);
        tracep->declBit(c+64,"riscv EX_unit pc_src_e", false,-1);
        tracep->declBus(c+58,"riscv EX_unit pc_target_e", false,-1, 31,0);
        tracep->declBus(c+59,"riscv EX_unit alu_result", false,-1, 31,0);
        tracep->declBus(c+11,"riscv EX_unit writedata", false,-1, 31,0);
        tracep->declBus(c+60,"riscv EX_unit ex_mem_pc_plus_4_e", false,-1, 31,0);
        tracep->declBus(c+61,"riscv EX_unit ex_mem_rd", false,-1, 4,0);
        tracep->declBit(c+62,"riscv EX_unit ex_mem_regwrite_e", false,-1);
        tracep->declBus(c+63,"riscv EX_unit ex_mem_result_src_e", false,-1, 1,0);
        tracep->declBit(c+12,"riscv EX_unit ex_mem_memwrite_e", false,-1);
        tracep->declBus(c+9,"riscv EX_unit ex_rs1_e", false,-1, 4,0);
        tracep->declBus(c+10,"riscv EX_unit ex_rs2_e", false,-1, 4,0);
        tracep->declBus(c+49,"riscv EX_unit ex_rd_e", false,-1, 4,0);
        tracep->declBus(c+92,"riscv EX_unit operand_a", false,-1, 31,0);
        tracep->declBus(c+93,"riscv EX_unit operand_b", false,-1, 31,0);
        tracep->declBus(c+94,"riscv EX_unit alu_result_temp", false,-1, 31,0);
        tracep->declBus(c+92,"riscv EX_unit hazard_a", false,-1, 31,0);
        tracep->declBus(c+131,"riscv EX_unit hazard_b", false,-1, 31,0);
        tracep->declBus(c+92,"riscv EX_unit ALU_unit in_a", false,-1, 31,0);
        tracep->declBus(c+93,"riscv EX_unit ALU_unit in_b", false,-1, 31,0);
        tracep->declBus(c+6,"riscv EX_unit ALU_unit alu_control", false,-1, 3,0);
        tracep->declBus(c+94,"riscv EX_unit ALU_unit alu_result", false,-1, 31,0);
        tracep->declBit(c+57,"riscv EX_unit ALU_unit zero_flag", false,-1);
        tracep->declBus(c+92,"riscv EX_unit branch_condition_unit in_a", false,-1, 31,0);
        tracep->declBus(c+93,"riscv EX_unit branch_condition_unit in_b", false,-1, 31,0);
        tracep->declBus(c+7,"riscv EX_unit branch_condition_unit branch_control", false,-1, 2,0);
        tracep->declBit(c+130,"riscv EX_unit branch_condition_unit branch_flag", false,-1);
        tracep->declBit(c+128,"riscv MEM_unit clk", false,-1);
        tracep->declBit(c+129,"riscv MEM_unit reset", false,-1);
        tracep->declBit(c+62,"riscv MEM_unit regwrite_m", false,-1);
        tracep->declBus(c+63,"riscv MEM_unit result_src_m", false,-1, 1,0);
        tracep->declBit(c+12,"riscv MEM_unit memwrite_m", false,-1);
        tracep->declBus(c+59,"riscv MEM_unit alu_result_m", false,-1, 31,0);
        tracep->declBus(c+11,"riscv MEM_unit writedata_m", false,-1, 31,0);
        tracep->declBus(c+61,"riscv MEM_unit rd_m", false,-1, 4,0);
        tracep->declBus(c+60,"riscv MEM_unit pc_plus_4_m", false,-1, 31,0);
        tracep->declBus(c+65,"riscv MEM_unit readdata", false,-1, 31,0);
        tracep->declBit(c+66,"riscv MEM_unit mem_wb_regwrite", false,-1);
        tracep->declBus(c+67,"riscv MEM_unit mem_wb_result_src", false,-1, 1,0);
        tracep->declBus(c+68,"riscv MEM_unit mem_wb_alu_result", false,-1, 31,0);
        tracep->declBus(c+69,"riscv MEM_unit mem_wb_pc_plus_4", false,-1, 31,0);
        tracep->declBus(c+70,"riscv MEM_unit mem_wb_rd", false,-1, 4,0);
        tracep->declBit(c+62,"riscv MEM_unit mem_regwrite_m", false,-1);
        tracep->declBus(c+59,"riscv MEM_unit mem_alu_result_m", false,-1, 31,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declBus(c+95+i*1,"riscv MEM_unit mem_array", true,(i+0), 31,0);}}
        tracep->declBit(c+128,"riscv WB_unit clk", false,-1);
        tracep->declBit(c+129,"riscv WB_unit reset", false,-1);
        tracep->declBit(c+66,"riscv WB_unit regwrite_w", false,-1);
        tracep->declBus(c+67,"riscv WB_unit result_src_w", false,-1, 1,0);
        tracep->declBus(c+68,"riscv WB_unit alu_result_w", false,-1, 31,0);
        tracep->declBus(c+65,"riscv WB_unit readdata_w", false,-1, 31,0);
        tracep->declBus(c+70,"riscv WB_unit rd_w", false,-1, 4,0);
        tracep->declBus(c+69,"riscv WB_unit pc_plus_4_w", false,-1, 31,0);
        tracep->declBit(c+71,"riscv WB_unit wb_regwrite", false,-1);
        tracep->declBus(c+72,"riscv WB_unit wb_rd", false,-1, 4,0);
        tracep->declBus(c+73,"riscv WB_unit wb_result", false,-1, 31,0);
        tracep->declBus(c+55,"riscv hazard_unit rs1_d", false,-1, 4,0);
        tracep->declBus(c+56,"riscv hazard_unit rs2_d", false,-1, 4,0);
        tracep->declBit(c+64,"riscv hazard_unit pc_src_e", false,-1);
        tracep->declBus(c+9,"riscv hazard_unit rs1_e", false,-1, 4,0);
        tracep->declBus(c+10,"riscv hazard_unit rs2_e", false,-1, 4,0);
        tracep->declBus(c+49,"riscv hazard_unit rd_e", false,-1, 4,0);
        tracep->declBit(c+127,"riscv hazard_unit result_src_e_0", false,-1);
        tracep->declBit(c+66,"riscv hazard_unit regwrite_w", false,-1);
        tracep->declBus(c+61,"riscv hazard_unit rd_m", false,-1, 4,0);
        tracep->declBit(c+62,"riscv hazard_unit regwrite_m", false,-1);
        tracep->declBus(c+70,"riscv hazard_unit rd_w", false,-1, 4,0);
        tracep->declBit(c+128,"riscv hazard_unit clk", false,-1);
        tracep->declBit(c+129,"riscv hazard_unit reset", false,-1);
        tracep->declBit(c+74,"riscv hazard_unit stall_f", false,-1);
        tracep->declBit(c+74,"riscv hazard_unit stall_d", false,-1);
        tracep->declBit(c+75,"riscv hazard_unit flush_d", false,-1);
        tracep->declBit(c+76,"riscv hazard_unit flush_e", false,-1);
        tracep->declBus(c+77,"riscv hazard_unit forward_operand_a_e", false,-1, 1,0);
        tracep->declBus(c+78,"riscv hazard_unit forward_operand_b_e", false,-1, 1,0);
        tracep->declBit(c+74,"riscv hazard_unit lw_stall", false,-1);
    }
}

void Vriscv::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vriscv::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vriscv__Syms* __restrict vlSymsp = static_cast<Vriscv__Syms*>(userp);
    Vriscv* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vriscv::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vriscv__Syms* __restrict vlSymsp = static_cast<Vriscv__Syms*>(userp);
    Vriscv* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullIData(oldp+1,(vlTOPp->riscv__DOT__id_ex_reg_a),32);
        tracep->fullIData(oldp+2,(vlTOPp->riscv__DOT__id_ex_reg_b),32);
        tracep->fullBit(oldp+3,(vlTOPp->riscv__DOT__id_ex_memwrite_d));
        tracep->fullBit(oldp+4,(vlTOPp->riscv__DOT__id_ex_jump_d));
        tracep->fullBit(oldp+5,(vlTOPp->riscv__DOT__id_ex_branch_d));
        tracep->fullCData(oldp+6,(vlTOPp->riscv__DOT__id_ex_alu_control_d),4);
        tracep->fullCData(oldp+7,(vlTOPp->riscv__DOT__id_ex_branch_control_d),3);
        tracep->fullBit(oldp+8,(vlTOPp->riscv__DOT__id_ex_alu_src_d));
        tracep->fullCData(oldp+9,(vlTOPp->riscv__DOT__id_ex_rs1_d_reg),5);
        tracep->fullCData(oldp+10,(vlTOPp->riscv__DOT__id_ex_rs2_d_reg),5);
        tracep->fullIData(oldp+11,(vlTOPp->riscv__DOT__ex_mem_writedata_e),32);
        tracep->fullBit(oldp+12,(vlTOPp->riscv__DOT__ex_mem_memwrite_e));
        tracep->fullIData(oldp+13,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[0]),32);
        tracep->fullIData(oldp+14,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[1]),32);
        tracep->fullIData(oldp+15,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[2]),32);
        tracep->fullIData(oldp+16,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[3]),32);
        tracep->fullIData(oldp+17,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[4]),32);
        tracep->fullIData(oldp+18,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[5]),32);
        tracep->fullIData(oldp+19,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[6]),32);
        tracep->fullIData(oldp+20,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[7]),32);
        tracep->fullIData(oldp+21,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[8]),32);
        tracep->fullIData(oldp+22,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[9]),32);
        tracep->fullIData(oldp+23,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[10]),32);
        tracep->fullIData(oldp+24,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[11]),32);
        tracep->fullIData(oldp+25,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[12]),32);
        tracep->fullIData(oldp+26,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[13]),32);
        tracep->fullIData(oldp+27,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[14]),32);
        tracep->fullIData(oldp+28,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[15]),32);
        tracep->fullIData(oldp+29,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[16]),32);
        tracep->fullIData(oldp+30,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[17]),32);
        tracep->fullIData(oldp+31,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[18]),32);
        tracep->fullIData(oldp+32,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[19]),32);
        tracep->fullIData(oldp+33,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[20]),32);
        tracep->fullIData(oldp+34,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[21]),32);
        tracep->fullIData(oldp+35,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[22]),32);
        tracep->fullIData(oldp+36,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[23]),32);
        tracep->fullIData(oldp+37,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[24]),32);
        tracep->fullIData(oldp+38,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[25]),32);
        tracep->fullIData(oldp+39,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[26]),32);
        tracep->fullIData(oldp+40,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[27]),32);
        tracep->fullIData(oldp+41,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[28]),32);
        tracep->fullIData(oldp+42,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[29]),32);
        tracep->fullIData(oldp+43,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[30]),32);
        tracep->fullIData(oldp+44,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[31]),32);
        tracep->fullIData(oldp+45,(vlTOPp->riscv__DOT__ID_unit__DOT__i),32);
        tracep->fullIData(oldp+46,(vlTOPp->riscv__DOT__if_id_instr),32);
        tracep->fullIData(oldp+47,(vlTOPp->riscv__DOT__if_id_pc),32);
        tracep->fullIData(oldp+48,(vlTOPp->riscv__DOT__if_id_pc_plus_4),32);
        tracep->fullCData(oldp+49,(vlTOPp->riscv__DOT__id_ex_rd),5);
        tracep->fullIData(oldp+50,(vlTOPp->riscv__DOT__id_ex_pc),32);
        tracep->fullIData(oldp+51,(vlTOPp->riscv__DOT__id_ex_imm),32);
        tracep->fullBit(oldp+52,(vlTOPp->riscv__DOT__id_ex_regwrite_d));
        tracep->fullCData(oldp+53,(vlTOPp->riscv__DOT__id_ex_result_src_d),2);
        tracep->fullIData(oldp+54,(vlTOPp->riscv__DOT__id_ex_pc_plus_4),32);
        tracep->fullCData(oldp+55,((0x1fU & (vlTOPp->riscv__DOT__if_id_instr 
                                             >> 0xfU))),5);
        tracep->fullCData(oldp+56,((0x1fU & (vlTOPp->riscv__DOT__if_id_instr 
                                             >> 0x14U))),5);
        tracep->fullBit(oldp+57,(vlTOPp->riscv__DOT__ex_mem_zero_flag_e));
        tracep->fullIData(oldp+58,((vlTOPp->riscv__DOT__id_ex_pc 
                                    + vlTOPp->riscv__DOT__id_ex_imm)),32);
        tracep->fullIData(oldp+59,(vlTOPp->riscv__DOT__ex_mem_alu_result_e),32);
        tracep->fullIData(oldp+60,(vlTOPp->riscv__DOT__ex_mem_pc_plus_4_e),32);
        tracep->fullCData(oldp+61,(vlTOPp->riscv__DOT__ex_mem_rd_e),5);
        tracep->fullBit(oldp+62,(vlTOPp->riscv__DOT__ex_mem_regwrite_e));
        tracep->fullCData(oldp+63,(vlTOPp->riscv__DOT__ex_mem_result_src_e),2);
        tracep->fullBit(oldp+64,(vlTOPp->riscv__DOT__ex_mem_pc_src_e));
        tracep->fullIData(oldp+65,(vlTOPp->riscv__DOT__mem_wb_readdata_w),32);
        tracep->fullBit(oldp+66,(vlTOPp->riscv__DOT__mem_wb_regwrite_w));
        tracep->fullCData(oldp+67,(vlTOPp->riscv__DOT__mem_wb_result_src_w),2);
        tracep->fullIData(oldp+68,(vlTOPp->riscv__DOT__mem_wb_alu_result_w),32);
        tracep->fullIData(oldp+69,(vlTOPp->riscv__DOT__mem_wb_pc_plus_4_w),32);
        tracep->fullCData(oldp+70,(vlTOPp->riscv__DOT__mem_wb_rd_w),5);
        tracep->fullBit(oldp+71,(vlTOPp->riscv__DOT__wb_regwrite));
        tracep->fullCData(oldp+72,(vlTOPp->riscv__DOT__wb_rd),5);
        tracep->fullIData(oldp+73,(vlTOPp->riscv__DOT__wb_result),32);
        tracep->fullBit(oldp+74,(vlTOPp->riscv__DOT__hazard_unit__DOT__lw_stall));
        tracep->fullBit(oldp+75,(vlTOPp->riscv__DOT__flush_d));
        tracep->fullBit(oldp+76,(vlTOPp->riscv__DOT__flush_e));
        tracep->fullCData(oldp+77,(vlTOPp->riscv__DOT__forward_operand_a_e),2);
        tracep->fullCData(oldp+78,(vlTOPp->riscv__DOT__forward_operand_b_e),2);
        tracep->fullIData(oldp+79,(vlTOPp->riscv__DOT__IF_unit__DOT__next_pc),32);
        tracep->fullCData(oldp+80,((0x7fU & vlTOPp->riscv__DOT__if_id_instr)),7);
        tracep->fullCData(oldp+81,((7U & (vlTOPp->riscv__DOT__if_id_instr 
                                          >> 0xcU))),3);
        tracep->fullBit(oldp+82,((1U & (vlTOPp->riscv__DOT__if_id_instr 
                                        >> 0x1eU))));
        tracep->fullIData(oldp+83,(vlTOPp->riscv__DOT__ID_unit__DOT__immediate_temp),32);
        tracep->fullBit(oldp+84,((1U & ((IData)(vlTOPp->riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals) 
                                        >> 6U))));
        tracep->fullBit(oldp+85,((1U & ((IData)(vlTOPp->riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals) 
                                        >> 4U))));
        tracep->fullBit(oldp+86,((1U & (IData)(vlTOPp->riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals))));
        tracep->fullBit(oldp+87,((1U & ((IData)(vlTOPp->riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals) 
                                        >> 1U))));
        tracep->fullBit(oldp+88,((1U & ((IData)(vlTOPp->riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals) 
                                        >> 5U))));
        tracep->fullCData(oldp+89,(((0x40U & vlTOPp->riscv__DOT__if_id_instr)
                                     ? 0U : ((0x20U 
                                              & vlTOPp->riscv__DOT__if_id_instr)
                                              ? ((0x10U 
                                                  & vlTOPp->riscv__DOT__if_id_instr)
                                                  ? 
                                                 ((8U 
                                                   & vlTOPp->riscv__DOT__if_id_instr)
                                                   ? 0U
                                                   : 
                                                  ((4U 
                                                    & vlTOPp->riscv__DOT__if_id_instr)
                                                    ? 0U
                                                    : 
                                                   ((2U 
                                                     & vlTOPp->riscv__DOT__if_id_instr)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->riscv__DOT__if_id_instr)
                                                      ? 
                                                     ((8U 
                                                       & (vlTOPp->riscv__DOT__if_id_instr 
                                                          >> 0x1bU)) 
                                                      | (7U 
                                                         & (vlTOPp->riscv__DOT__if_id_instr 
                                                            >> 0xcU)))
                                                      : 0U)
                                                     : 0U)))
                                                  : 0U)
                                              : ((0x10U 
                                                  & vlTOPp->riscv__DOT__if_id_instr)
                                                  ? 
                                                 ((8U 
                                                   & vlTOPp->riscv__DOT__if_id_instr)
                                                   ? 0U
                                                   : 
                                                  ((4U 
                                                    & vlTOPp->riscv__DOT__if_id_instr)
                                                    ? 0U
                                                    : 
                                                   ((2U 
                                                     & vlTOPp->riscv__DOT__if_id_instr)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->riscv__DOT__if_id_instr)
                                                      ? 
                                                     ((8U 
                                                       & (vlTOPp->riscv__DOT__if_id_instr 
                                                          >> 0x1bU)) 
                                                      | (7U 
                                                         & (vlTOPp->riscv__DOT__if_id_instr 
                                                            >> 0xcU)))
                                                      : 0U)
                                                     : 0U)))
                                                  : 0U)))),4);
        tracep->fullCData(oldp+90,((3U & ((IData)(vlTOPp->riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals) 
                                          >> 2U))),2);
        tracep->fullCData(oldp+91,(vlTOPp->riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals),7);
        tracep->fullIData(oldp+92,(vlTOPp->riscv__DOT__EX_unit__DOT__hazard_a),32);
        tracep->fullIData(oldp+93,(vlTOPp->riscv__DOT__EX_unit__DOT__operand_b),32);
        tracep->fullIData(oldp+94,(vlTOPp->riscv__DOT__EX_unit__DOT__alu_result_temp),32);
        tracep->fullIData(oldp+95,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[0]),32);
        tracep->fullIData(oldp+96,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[1]),32);
        tracep->fullIData(oldp+97,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[2]),32);
        tracep->fullIData(oldp+98,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[3]),32);
        tracep->fullIData(oldp+99,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[4]),32);
        tracep->fullIData(oldp+100,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[5]),32);
        tracep->fullIData(oldp+101,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[6]),32);
        tracep->fullIData(oldp+102,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[7]),32);
        tracep->fullIData(oldp+103,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[8]),32);
        tracep->fullIData(oldp+104,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[9]),32);
        tracep->fullIData(oldp+105,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[10]),32);
        tracep->fullIData(oldp+106,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[11]),32);
        tracep->fullIData(oldp+107,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[12]),32);
        tracep->fullIData(oldp+108,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[13]),32);
        tracep->fullIData(oldp+109,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[14]),32);
        tracep->fullIData(oldp+110,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[15]),32);
        tracep->fullIData(oldp+111,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[16]),32);
        tracep->fullIData(oldp+112,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[17]),32);
        tracep->fullIData(oldp+113,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[18]),32);
        tracep->fullIData(oldp+114,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[19]),32);
        tracep->fullIData(oldp+115,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[20]),32);
        tracep->fullIData(oldp+116,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[21]),32);
        tracep->fullIData(oldp+117,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[22]),32);
        tracep->fullIData(oldp+118,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[23]),32);
        tracep->fullIData(oldp+119,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[24]),32);
        tracep->fullIData(oldp+120,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[25]),32);
        tracep->fullIData(oldp+121,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[26]),32);
        tracep->fullIData(oldp+122,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[27]),32);
        tracep->fullIData(oldp+123,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[28]),32);
        tracep->fullIData(oldp+124,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[29]),32);
        tracep->fullIData(oldp+125,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[30]),32);
        tracep->fullIData(oldp+126,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[31]),32);
        tracep->fullBit(oldp+127,((1U & (IData)(vlTOPp->riscv__DOT__id_ex_result_src_d))));
        tracep->fullBit(oldp+128,(vlTOPp->clk));
        tracep->fullBit(oldp+129,(vlTOPp->reset));
        tracep->fullBit(oldp+130,(((4U & (IData)(vlTOPp->riscv__DOT__id_ex_branch_control_d))
                                    ? ((2U & (IData)(vlTOPp->riscv__DOT__id_ex_branch_control_d))
                                        ? ((1U & (IData)(vlTOPp->riscv__DOT__id_ex_branch_control_d))
                                            ? (vlTOPp->riscv__DOT__EX_unit__DOT__hazard_a 
                                               >= vlTOPp->riscv__DOT__EX_unit__DOT__operand_b)
                                            : (vlTOPp->riscv__DOT__EX_unit__DOT__hazard_a 
                                               < vlTOPp->riscv__DOT__EX_unit__DOT__operand_b))
                                        : ((1U & (IData)(vlTOPp->riscv__DOT__id_ex_branch_control_d))
                                            ? VL_GTES_III(1,32,32, vlTOPp->riscv__DOT__EX_unit__DOT__hazard_a, vlTOPp->riscv__DOT__EX_unit__DOT__operand_b)
                                            : VL_LTS_III(1,32,32, vlTOPp->riscv__DOT__EX_unit__DOT__hazard_a, vlTOPp->riscv__DOT__EX_unit__DOT__operand_b)))
                                    : ((~ ((IData)(vlTOPp->riscv__DOT__id_ex_branch_control_d) 
                                           >> 1U)) 
                                       & ((1U & (IData)(vlTOPp->riscv__DOT__id_ex_branch_control_d))
                                           ? (vlTOPp->riscv__DOT__EX_unit__DOT__hazard_a 
                                              != vlTOPp->riscv__DOT__EX_unit__DOT__operand_b)
                                           : (vlTOPp->riscv__DOT__EX_unit__DOT__hazard_a 
                                              == vlTOPp->riscv__DOT__EX_unit__DOT__operand_b))))));
        tracep->fullIData(oldp+131,(((0U == (IData)(vlTOPp->riscv__DOT__forward_operand_b_e))
                                      ? vlTOPp->riscv__DOT__id_ex_reg_b
                                      : ((1U == (IData)(vlTOPp->riscv__DOT__forward_operand_b_e))
                                          ? vlTOPp->riscv__DOT__mem_wb_alu_result_w
                                          : ((2U == (IData)(vlTOPp->riscv__DOT__forward_operand_b_e))
                                              ? vlTOPp->riscv__DOT__ex_mem_alu_result_e
                                              : 0U)))),32);
        tracep->fullIData(oldp+132,(vlTOPp->riscv__DOT__alu_result),32);
        tracep->fullBit(oldp+133,(vlTOPp->riscv__DOT__zero_flag));
        tracep->fullIData(oldp+134,(vlTOPp->riscv__DOT__IF_unit__DOT__instr_mem[0]),32);
        tracep->fullIData(oldp+135,(vlTOPp->riscv__DOT__IF_unit__DOT__instr_mem[1]),32);
        tracep->fullIData(oldp+136,(vlTOPp->riscv__DOT__IF_unit__DOT__instr_mem[2]),32);
        tracep->fullIData(oldp+137,(vlTOPp->riscv__DOT__IF_unit__DOT__instr_mem[3]),32);
        tracep->fullIData(oldp+138,(vlTOPp->riscv__DOT__IF_unit__DOT__instr_mem[4]),32);
        tracep->fullIData(oldp+139,(vlTOPp->riscv__DOT__IF_unit__DOT__instr_mem[5]),32);
        tracep->fullIData(oldp+140,(vlTOPp->riscv__DOT__IF_unit__DOT__instr_mem[6]),32);
        tracep->fullIData(oldp+141,(vlTOPp->riscv__DOT__IF_unit__DOT__instr_mem[7]),32);
        tracep->fullIData(oldp+142,(vlTOPp->riscv__DOT__IF_unit__DOT__instr_mem[8]),32);
        tracep->fullIData(oldp+143,(vlTOPp->riscv__DOT__IF_unit__DOT__instr_mem[9]),32);
        tracep->fullIData(oldp+144,(vlTOPp->riscv__DOT__IF_unit__DOT__instr_mem[10]),32);
        tracep->fullIData(oldp+145,(vlTOPp->riscv__DOT__IF_unit__DOT__instr_mem[11]),32);
        tracep->fullIData(oldp+146,(vlTOPp->riscv__DOT__IF_unit__DOT__instr_mem[12]),32);
        tracep->fullIData(oldp+147,(vlTOPp->riscv__DOT__IF_unit__DOT__instr_mem[13]),32);
        tracep->fullIData(oldp+148,(vlTOPp->riscv__DOT__IF_unit__DOT__instr_mem[14]),32);
        tracep->fullIData(oldp+149,(vlTOPp->riscv__DOT__IF_unit__DOT__instr_mem[15]),32);
        tracep->fullIData(oldp+150,(vlTOPp->riscv__DOT__IF_unit__DOT__instr_mem[16]),32);
        tracep->fullIData(oldp+151,(vlTOPp->riscv__DOT__IF_unit__DOT__instr_mem[17]),32);
        tracep->fullIData(oldp+152,(vlTOPp->riscv__DOT__IF_unit__DOT__instr_mem[18]),32);
        tracep->fullIData(oldp+153,(vlTOPp->riscv__DOT__IF_unit__DOT__instr_mem[19]),32);
        tracep->fullIData(oldp+154,(vlTOPp->riscv__DOT__IF_unit__DOT__instr_mem[20]),32);
        tracep->fullIData(oldp+155,(vlTOPp->riscv__DOT__IF_unit__DOT__instr_mem[21]),32);
        tracep->fullIData(oldp+156,(vlTOPp->riscv__DOT__IF_unit__DOT__instr_mem[22]),32);
        tracep->fullIData(oldp+157,(vlTOPp->riscv__DOT__IF_unit__DOT__instr_mem[23]),32);
        tracep->fullIData(oldp+158,(vlTOPp->riscv__DOT__IF_unit__DOT__instr_mem[24]),32);
        tracep->fullIData(oldp+159,(vlTOPp->riscv__DOT__IF_unit__DOT__instr_mem[25]),32);
        tracep->fullIData(oldp+160,(vlTOPp->riscv__DOT__IF_unit__DOT__instr_mem[26]),32);
        tracep->fullIData(oldp+161,(vlTOPp->riscv__DOT__IF_unit__DOT__instr_mem[27]),32);
        tracep->fullIData(oldp+162,(vlTOPp->riscv__DOT__IF_unit__DOT__instr_mem[28]),32);
        tracep->fullIData(oldp+163,(vlTOPp->riscv__DOT__IF_unit__DOT__instr_mem[29]),32);
        tracep->fullIData(oldp+164,(vlTOPp->riscv__DOT__IF_unit__DOT__instr_mem[30]),32);
        tracep->fullIData(oldp+165,(vlTOPp->riscv__DOT__IF_unit__DOT__instr_mem[31]),32);
        tracep->fullCData(oldp+166,(3U),7);
        tracep->fullCData(oldp+167,(0x23U),7);
        tracep->fullCData(oldp+168,(0x63U),7);
        tracep->fullCData(oldp+169,(0x13U),7);
        tracep->fullCData(oldp+170,(0x6fU),7);
        tracep->fullCData(oldp+171,(0x33U),7);
    }
}

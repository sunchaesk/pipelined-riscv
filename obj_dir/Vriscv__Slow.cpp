// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vriscv.h for the primary calling header

#include "Vriscv.h"
#include "Vriscv__Syms.h"

//==========
CData/*6:0*/ Vriscv::__Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[128];

VL_CTOR_IMP(Vriscv) {
    Vriscv__Syms* __restrict vlSymsp = __VlSymsp = new Vriscv__Syms(this, name());
    Vriscv* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vriscv::__Vconfigure(Vriscv__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vriscv::~Vriscv() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

void Vriscv::_settle__TOP__2(Vriscv__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv::_settle__TOP__2\n"); );
    Vriscv* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->riscv__DOT__ID_unit__DOT__immediate_temp 
        = ((0x40U & vlTOPp->riscv__DOT__if_id_instr)
            ? ((0x20U & vlTOPp->riscv__DOT__if_id_instr)
                ? ((0x10U & vlTOPp->riscv__DOT__if_id_instr)
                    ? 0U : ((8U & vlTOPp->riscv__DOT__if_id_instr)
                             ? ((4U & vlTOPp->riscv__DOT__if_id_instr)
                                 ? ((2U & vlTOPp->riscv__DOT__if_id_instr)
                                     ? ((1U & vlTOPp->riscv__DOT__if_id_instr)
                                         ? ((0xffe00000U 
                                             & ((- (IData)(
                                                           (1U 
                                                            & (vlTOPp->riscv__DOT__if_id_instr 
                                                               >> 0x1fU)))) 
                                                << 0x15U)) 
                                            | ((0x100000U 
                                                & (vlTOPp->riscv__DOT__if_id_instr 
                                                   >> 0xbU)) 
                                               | ((0xff000U 
                                                   & vlTOPp->riscv__DOT__if_id_instr) 
                                                  | ((0x800U 
                                                      & (vlTOPp->riscv__DOT__if_id_instr 
                                                         >> 9U)) 
                                                     | ((0x7e0U 
                                                         & (vlTOPp->riscv__DOT__if_id_instr 
                                                            >> 0x14U)) 
                                                        | (0x1eU 
                                                           & (vlTOPp->riscv__DOT__if_id_instr 
                                                              >> 0x14U)))))))
                                         : 0U) : 0U)
                                 : 0U) : ((4U & vlTOPp->riscv__DOT__if_id_instr)
                                           ? 0U : (
                                                   (2U 
                                                    & vlTOPp->riscv__DOT__if_id_instr)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->riscv__DOT__if_id_instr)
                                                     ? 
                                                    ((0xfffff000U 
                                                      & ((- (IData)(
                                                                    (1U 
                                                                     & (vlTOPp->riscv__DOT__if_id_instr 
                                                                        >> 0x1fU)))) 
                                                         << 0xcU)) 
                                                     | ((0x800U 
                                                         & (vlTOPp->riscv__DOT__if_id_instr 
                                                            << 4U)) 
                                                        | ((0x7e0U 
                                                            & (vlTOPp->riscv__DOT__if_id_instr 
                                                               >> 0x14U)) 
                                                           | (0x1eU 
                                                              & (vlTOPp->riscv__DOT__if_id_instr 
                                                                 >> 7U)))))
                                                     : 0U)
                                                    : 0U))))
                : 0U) : ((0x20U & vlTOPp->riscv__DOT__if_id_instr)
                          ? ((0x10U & vlTOPp->riscv__DOT__if_id_instr)
                              ? 0U : ((8U & vlTOPp->riscv__DOT__if_id_instr)
                                       ? 0U : ((4U 
                                                & vlTOPp->riscv__DOT__if_id_instr)
                                                ? 0U
                                                : (
                                                   (2U 
                                                    & vlTOPp->riscv__DOT__if_id_instr)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->riscv__DOT__if_id_instr)
                                                     ? 
                                                    ((0xfffff000U 
                                                      & ((- (IData)(
                                                                    (1U 
                                                                     & (vlTOPp->riscv__DOT__if_id_instr 
                                                                        >> 0x1fU)))) 
                                                         << 0xcU)) 
                                                     | ((0xfe0U 
                                                         & (vlTOPp->riscv__DOT__if_id_instr 
                                                            >> 0x14U)) 
                                                        | (0x1fU 
                                                           & (vlTOPp->riscv__DOT__if_id_instr 
                                                              >> 7U))))
                                                     : 0U)
                                                    : 0U))))
                          : ((8U & vlTOPp->riscv__DOT__if_id_instr)
                              ? 0U : ((4U & vlTOPp->riscv__DOT__if_id_instr)
                                       ? 0U : ((2U 
                                                & vlTOPp->riscv__DOT__if_id_instr)
                                                ? (
                                                   (1U 
                                                    & vlTOPp->riscv__DOT__if_id_instr)
                                                    ? 
                                                   ((0xfffff000U 
                                                     & ((- (IData)(
                                                                   (1U 
                                                                    & (vlTOPp->riscv__DOT__if_id_instr 
                                                                       >> 0x1fU)))) 
                                                        << 0xcU)) 
                                                    | (0xfffU 
                                                       & (vlTOPp->riscv__DOT__if_id_instr 
                                                          >> 0x14U)))
                                                    : 0U)
                                                : 0U)))));
    vlTOPp->__Vtableidx1 = (0x7fU & vlTOPp->riscv__DOT__if_id_instr);
    vlTOPp->riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals 
        = vlTOPp->__Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals
        [vlTOPp->__Vtableidx1];
    vlTOPp->riscv__DOT__IF_unit__DOT__next_count = 
        ((IData)(vlTOPp->riscv__DOT__pc_src) ? 0xaU
          : ((IData)(4U) + vlTOPp->riscv__DOT__IF_unit__DOT__curr_count));
}

void Vriscv::_eval_initial(Vriscv__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv::_eval_initial\n"); );
    Vriscv* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

void Vriscv::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv::final\n"); );
    // Variables
    Vriscv__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vriscv* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vriscv::_eval_settle(Vriscv__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv::_eval_settle\n"); );
    Vriscv* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void Vriscv::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    instr_out = VL_RAND_RESET_I(32);
    pc_out = VL_RAND_RESET_I(32);
    riscv__DOT__pc_src = VL_RAND_RESET_I(1);
    riscv__DOT__if_id_instr = VL_RAND_RESET_I(32);
    riscv__DOT__id_ex_rd = VL_RAND_RESET_I(5);
    riscv__DOT__id_ex_pc = VL_RAND_RESET_I(32);
    riscv__DOT__id_ex_reg_a = VL_RAND_RESET_I(32);
    riscv__DOT__id_ex_reg_b = VL_RAND_RESET_I(32);
    riscv__DOT__id_ex_imm = VL_RAND_RESET_I(32);
    riscv__DOT__id_ex_regwrite_d = VL_RAND_RESET_I(1);
    riscv__DOT__id_ex_result_src_d = VL_RAND_RESET_I(2);
    riscv__DOT__id_ex_memwrite_d = VL_RAND_RESET_I(1);
    riscv__DOT__id_ex_jump_d = VL_RAND_RESET_I(1);
    riscv__DOT__id_ex_branch_d = VL_RAND_RESET_I(1);
    riscv__DOT__id_ex_alu_control_d = VL_RAND_RESET_I(4);
    riscv__DOT__id_ex_alu_src_d = VL_RAND_RESET_I(1);
    riscv__DOT__id_ex_pc_plus_4 = VL_RAND_RESET_I(32);
    riscv__DOT__ex_mem_alu_result = VL_RAND_RESET_I(32);
    riscv__DOT__ex_mem_reg_b = VL_RAND_RESET_I(32);
    riscv__DOT__ex_mem_instr = VL_RAND_RESET_I(32);
    riscv__DOT__mem_wb_alu_result = VL_RAND_RESET_I(32);
    riscv__DOT__mem_wb_instr = VL_RAND_RESET_I(32);
    riscv__DOT__mem_wb_data = VL_RAND_RESET_I(32);
    riscv__DOT__alu_result = VL_RAND_RESET_I(32);
    riscv__DOT__zero_flag = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<256; ++__Vi0) {
        riscv__DOT__IF_unit__DOT__instr_mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    riscv__DOT__IF_unit__DOT__next_count = VL_RAND_RESET_I(32);
    riscv__DOT__IF_unit__DOT__curr_count = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        riscv__DOT__ID_unit__DOT__reg_array[__Vi0] = VL_RAND_RESET_I(32);
    }
    riscv__DOT__ID_unit__DOT__immediate_temp = VL_RAND_RESET_I(32);
    riscv__DOT__ID_unit__DOT__i = VL_RAND_RESET_I(32);
    riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals = VL_RAND_RESET_I(7);
    __Vtableidx1 = 0;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[0] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[1] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[2] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[3] = 0x44U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[4] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[5] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[6] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[7] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[8] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[9] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[10] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[11] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[12] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[13] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[14] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[15] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[16] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[17] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[18] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[19] = 0x60U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[20] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[21] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[22] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[23] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[24] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[25] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[26] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[27] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[28] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[29] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[30] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[31] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[32] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[33] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[34] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[35] = 0x20U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[36] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[37] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[38] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[39] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[40] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[41] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[42] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[43] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[44] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[45] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[46] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[47] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[48] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[49] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[50] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[51] = 0x40U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[52] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[53] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[54] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[55] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[56] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[57] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[58] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[59] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[60] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[61] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[62] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[63] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[64] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[65] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[66] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[67] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[68] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[69] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[70] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[71] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[72] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[73] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[74] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[75] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[76] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[77] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[78] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[79] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[80] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[81] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[82] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[83] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[84] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[85] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[86] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[87] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[88] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[89] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[90] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[91] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[92] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[93] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[94] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[95] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[96] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[97] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[98] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[99] = 8U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[100] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[101] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[102] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[103] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[104] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[105] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[106] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[107] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[108] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[109] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[110] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[111] = 0x42U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[112] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[113] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[114] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[115] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[116] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[117] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[118] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[119] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[120] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[121] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[122] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[123] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[124] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[125] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[126] = 0U;
    __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[127] = 0U;
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}

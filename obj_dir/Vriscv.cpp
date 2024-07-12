// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vriscv.h for the primary calling header

#include "Vriscv.h"
#include "Vriscv__Syms.h"

//==========

void Vriscv::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vriscv::eval\n"); );
    Vriscv__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vriscv* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("riscv.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vriscv::_eval_initial_loop(Vriscv__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("riscv.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vriscv::_sequent__TOP__1(Vriscv__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv::_sequent__TOP__1\n"); );
    Vriscv* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vdly__riscv__DOT__IF_unit__DOT__next_pc 
        = vlTOPp->riscv__DOT__IF_unit__DOT__next_pc;
    vlTOPp->__Vdly__riscv__DOT__if_id_pc = vlTOPp->riscv__DOT__if_id_pc;
    vlTOPp->__Vdlyvset__riscv__DOT__MEM_unit__DOT__mem_array__v0 = 0U;
    if (((IData)(vlTOPp->reset) | (IData)(vlTOPp->riscv__DOT__flush_d))) {
        vlTOPp->riscv__DOT__id_ex_jump_d = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->riscv__DOT__hazard_unit__DOT__lw_stall)))) {
            vlTOPp->riscv__DOT__id_ex_jump_d = (1U 
                                                & (IData)(vlTOPp->riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals));
        }
    }
    if (((IData)(vlTOPp->reset) | (IData)(vlTOPp->riscv__DOT__flush_d))) {
        vlTOPp->riscv__DOT__id_ex_branch_d = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->riscv__DOT__hazard_unit__DOT__lw_stall)))) {
            vlTOPp->riscv__DOT__id_ex_branch_d = (1U 
                                                  & ((IData)(vlTOPp->riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals) 
                                                     >> 1U));
        }
    }
    if (((IData)(vlTOPp->reset) | (IData)(vlTOPp->riscv__DOT__flush_d))) {
        vlTOPp->riscv__DOT__id_ex_alu_src_d = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->riscv__DOT__hazard_unit__DOT__lw_stall)))) {
            vlTOPp->riscv__DOT__id_ex_alu_src_d = (1U 
                                                   & ((IData)(vlTOPp->riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals) 
                                                      >> 5U));
        }
    }
    if (((IData)(vlTOPp->reset) | (IData)(vlTOPp->riscv__DOT__flush_d))) {
        vlTOPp->riscv__DOT__id_ex_alu_control_d = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->riscv__DOT__hazard_unit__DOT__lw_stall)))) {
            vlTOPp->riscv__DOT__id_ex_alu_control_d 
                = ((0x40U & vlTOPp->riscv__DOT__if_id_instr)
                    ? 0U : ((0x20U & vlTOPp->riscv__DOT__if_id_instr)
                             ? ((0x10U & vlTOPp->riscv__DOT__if_id_instr)
                                 ? ((8U & vlTOPp->riscv__DOT__if_id_instr)
                                     ? 0U : ((4U & vlTOPp->riscv__DOT__if_id_instr)
                                              ? 0U : 
                                             ((2U & vlTOPp->riscv__DOT__if_id_instr)
                                               ? ((1U 
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
                                 : 0U) : ((0x10U & vlTOPp->riscv__DOT__if_id_instr)
                                           ? ((8U & vlTOPp->riscv__DOT__if_id_instr)
                                               ? 0U
                                               : ((4U 
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
                                           : 0U)));
        }
    }
    if (((IData)(vlTOPp->reset) | (IData)(vlTOPp->riscv__DOT__flush_d))) {
        vlTOPp->riscv__DOT__id_ex_branch_control_d = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->riscv__DOT__hazard_unit__DOT__lw_stall)))) {
            vlTOPp->riscv__DOT__id_ex_branch_control_d 
                = (7U & (vlTOPp->riscv__DOT__if_id_instr 
                         >> 0xcU));
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->reset) | (IData)(vlTOPp->riscv__DOT__flush_d))))) {
        if ((1U & (~ (IData)(vlTOPp->riscv__DOT__hazard_unit__DOT__lw_stall)))) {
            vlTOPp->riscv__DOT__id_ex_reg_a = vlTOPp->riscv__DOT__ID_unit__DOT__reg_array
                [(0x1fU & (vlTOPp->riscv__DOT__if_id_instr 
                           >> 0xfU))];
        }
    }
    if (((IData)(vlTOPp->reset) | (IData)(vlTOPp->riscv__DOT__flush_d))) {
        vlTOPp->riscv__DOT__id_ex_rs1_d_reg = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->riscv__DOT__hazard_unit__DOT__lw_stall)))) {
            vlTOPp->riscv__DOT__id_ex_rs1_d_reg = (0x1fU 
                                                   & (vlTOPp->riscv__DOT__if_id_instr 
                                                      >> 0xfU));
        }
    }
    if (((IData)(vlTOPp->reset) | (IData)(vlTOPp->riscv__DOT__flush_d))) {
        vlTOPp->riscv__DOT__id_ex_rs2_d_reg = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->riscv__DOT__hazard_unit__DOT__lw_stall)))) {
            vlTOPp->riscv__DOT__id_ex_rs2_d_reg = (0x1fU 
                                                   & (vlTOPp->riscv__DOT__if_id_instr 
                                                      >> 0x14U));
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (vlTOPp->riscv__DOT__ex_mem_memwrite_e) {
            vlTOPp->__Vdlyvval__riscv__DOT__MEM_unit__DOT__mem_array__v0 
                = vlTOPp->riscv__DOT__ex_mem_writedata_e;
            vlTOPp->__Vdlyvset__riscv__DOT__MEM_unit__DOT__mem_array__v0 = 1U;
            vlTOPp->__Vdlyvdim0__riscv__DOT__MEM_unit__DOT__mem_array__v0 
                = (0x1fU & (vlTOPp->riscv__DOT__ex_mem_alu_result_e 
                            >> 2U));
        }
    }
    vlTOPp->riscv__DOT__ex_mem_memwrite_e = ((~ ((IData)(vlTOPp->reset) 
                                                 | (IData)(vlTOPp->riscv__DOT__flush_e))) 
                                             & (IData)(vlTOPp->riscv__DOT__id_ex_memwrite_d));
    vlTOPp->riscv__DOT__ex_mem_writedata_e = (((IData)(vlTOPp->reset) 
                                               | (IData)(vlTOPp->riscv__DOT__flush_e))
                                               ? 0U
                                               : vlTOPp->riscv__DOT__id_ex_reg_b);
    if (((IData)(vlTOPp->reset) | (IData)(vlTOPp->riscv__DOT__flush_d))) {
        vlTOPp->riscv__DOT__id_ex_memwrite_d = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->riscv__DOT__hazard_unit__DOT__lw_stall)))) {
            vlTOPp->riscv__DOT__id_ex_memwrite_d = 
                (1U & ((IData)(vlTOPp->riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals) 
                       >> 4U));
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->reset) | (IData)(vlTOPp->riscv__DOT__flush_d))))) {
        if ((1U & (~ (IData)(vlTOPp->riscv__DOT__hazard_unit__DOT__lw_stall)))) {
            vlTOPp->riscv__DOT__id_ex_reg_b = vlTOPp->riscv__DOT__ID_unit__DOT__reg_array
                [(0x1fU & (vlTOPp->riscv__DOT__if_id_instr 
                           >> 0x14U))];
        }
    }
}

VL_INLINE_OPT void Vriscv::_sequent__TOP__2(Vriscv__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv::_sequent__TOP__2\n"); );
    Vriscv* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdlyvset__riscv__DOT__ID_unit__DOT__reg_array__v0;
    CData/*4:0*/ __Vdlyvdim0__riscv__DOT__ID_unit__DOT__reg_array__v32;
    CData/*0:0*/ __Vdlyvset__riscv__DOT__ID_unit__DOT__reg_array__v32;
    IData/*31:0*/ __Vdlyvval__riscv__DOT__ID_unit__DOT__reg_array__v32;
    // Body
    if (vlTOPp->reset) {
        vlTOPp->riscv__DOT__ID_unit__DOT__i = 0x20U;
    }
    __Vdlyvset__riscv__DOT__ID_unit__DOT__reg_array__v0 = 0U;
    __Vdlyvset__riscv__DOT__ID_unit__DOT__reg_array__v32 = 0U;
    if (vlTOPp->reset) {
        __Vdlyvset__riscv__DOT__ID_unit__DOT__reg_array__v0 = 1U;
    } else {
        if (vlTOPp->riscv__DOT__wb_regwrite) {
            if ((0U != (IData)(vlTOPp->riscv__DOT__wb_rd))) {
                __Vdlyvval__riscv__DOT__ID_unit__DOT__reg_array__v32 
                    = vlTOPp->riscv__DOT__wb_result;
                __Vdlyvset__riscv__DOT__ID_unit__DOT__reg_array__v32 = 1U;
                __Vdlyvdim0__riscv__DOT__ID_unit__DOT__reg_array__v32 
                    = vlTOPp->riscv__DOT__wb_rd;
            }
        }
    }
    if (__Vdlyvset__riscv__DOT__ID_unit__DOT__reg_array__v0) {
        vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[0U] = 0U;
        vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[1U] = 0U;
        vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[2U] = 0U;
        vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[3U] = 0U;
        vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[4U] = 0U;
        vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[5U] = 0U;
        vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[6U] = 0U;
        vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[7U] = 0U;
        vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[8U] = 0U;
        vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[9U] = 0U;
        vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[0xaU] = 0U;
        vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[0xbU] = 0U;
        vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[0xcU] = 0U;
        vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[0xdU] = 0U;
        vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[0xeU] = 0U;
        vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[0xfU] = 0U;
        vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[0x10U] = 0U;
        vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[0x11U] = 0U;
        vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[0x12U] = 0U;
        vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[0x13U] = 0U;
        vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[0x14U] = 0U;
        vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[0x15U] = 0U;
        vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[0x16U] = 0U;
        vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[0x17U] = 0U;
        vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[0x18U] = 0U;
        vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[0x19U] = 0U;
        vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[0x1aU] = 0U;
        vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[0x1bU] = 0U;
        vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[0x1cU] = 0U;
        vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[0x1dU] = 0U;
        vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[0x1eU] = 0U;
        vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[0x1fU] = 0U;
    }
    if (__Vdlyvset__riscv__DOT__ID_unit__DOT__reg_array__v32) {
        vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[__Vdlyvdim0__riscv__DOT__ID_unit__DOT__reg_array__v32] 
            = __Vdlyvval__riscv__DOT__ID_unit__DOT__reg_array__v32;
    }
}

VL_INLINE_OPT void Vriscv::_sequent__TOP__4(Vriscv__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv::_sequent__TOP__4\n"); );
    Vriscv* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->riscv__DOT__wb_regwrite = ((~ (IData)(vlTOPp->reset)) 
                                       & (IData)(vlTOPp->riscv__DOT__mem_wb_regwrite_w));
    if (vlTOPp->reset) {
        vlTOPp->riscv__DOT__wb_rd = 0U;
        vlTOPp->riscv__DOT__wb_result = 0U;
    } else {
        vlTOPp->riscv__DOT__wb_rd = vlTOPp->riscv__DOT__mem_wb_rd_w;
        vlTOPp->riscv__DOT__wb_result = ((0U == (IData)(vlTOPp->riscv__DOT__mem_wb_result_src_w))
                                          ? vlTOPp->riscv__DOT__mem_wb_alu_result_w
                                          : ((1U == (IData)(vlTOPp->riscv__DOT__mem_wb_result_src_w))
                                              ? vlTOPp->riscv__DOT__mem_wb_readdata_w
                                              : ((2U 
                                                  == (IData)(vlTOPp->riscv__DOT__mem_wb_result_src_w))
                                                  ? vlTOPp->riscv__DOT__mem_wb_pc_plus_4_w
                                                  : 0U)));
    }
    vlTOPp->riscv__DOT__mem_wb_regwrite_w = ((~ (IData)(vlTOPp->reset)) 
                                             & (IData)(vlTOPp->riscv__DOT__ex_mem_regwrite_e));
    if (vlTOPp->reset) {
        vlTOPp->riscv__DOT__mem_wb_rd_w = 0U;
        vlTOPp->riscv__DOT__mem_wb_result_src_w = 0U;
        vlTOPp->riscv__DOT__mem_wb_readdata_w = 0U;
        vlTOPp->riscv__DOT__mem_wb_alu_result_w = 0U;
        vlTOPp->riscv__DOT__mem_wb_pc_plus_4_w = 0U;
    } else {
        vlTOPp->riscv__DOT__mem_wb_rd_w = vlTOPp->riscv__DOT__ex_mem_rd_e;
        vlTOPp->riscv__DOT__mem_wb_result_src_w = vlTOPp->riscv__DOT__ex_mem_result_src_e;
        vlTOPp->riscv__DOT__mem_wb_readdata_w = vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array
            [(0x1fU & (vlTOPp->riscv__DOT__ex_mem_alu_result_e 
                       >> 2U))];
        vlTOPp->riscv__DOT__mem_wb_alu_result_w = vlTOPp->riscv__DOT__ex_mem_alu_result_e;
        vlTOPp->riscv__DOT__mem_wb_pc_plus_4_w = vlTOPp->riscv__DOT__ex_mem_pc_plus_4_e;
    }
    if (vlTOPp->__Vdlyvset__riscv__DOT__MEM_unit__DOT__mem_array__v0) {
        vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[vlTOPp->__Vdlyvdim0__riscv__DOT__MEM_unit__DOT__mem_array__v0] 
            = vlTOPp->__Vdlyvval__riscv__DOT__MEM_unit__DOT__mem_array__v0;
    }
    vlTOPp->riscv__DOT__ex_mem_regwrite_e = ((~ ((IData)(vlTOPp->reset) 
                                                 | (IData)(vlTOPp->riscv__DOT__flush_e))) 
                                             & (IData)(vlTOPp->riscv__DOT__id_ex_regwrite_d));
    if (((IData)(vlTOPp->reset) | (IData)(vlTOPp->riscv__DOT__flush_e))) {
        vlTOPp->riscv__DOT__ex_mem_rd_e = 0U;
        vlTOPp->riscv__DOT__ex_mem_result_src_e = 0U;
        vlTOPp->riscv__DOT__ex_mem_alu_result_e = 0U;
        vlTOPp->riscv__DOT__ex_mem_pc_plus_4_e = 0U;
    } else {
        vlTOPp->riscv__DOT__ex_mem_rd_e = vlTOPp->riscv__DOT__id_ex_rd;
        vlTOPp->riscv__DOT__ex_mem_result_src_e = vlTOPp->riscv__DOT__id_ex_result_src_d;
        vlTOPp->riscv__DOT__ex_mem_alu_result_e = vlTOPp->riscv__DOT__EX_unit__DOT__alu_result_temp;
        vlTOPp->riscv__DOT__ex_mem_pc_plus_4_e = vlTOPp->riscv__DOT__id_ex_pc_plus_4;
    }
    if (((IData)(vlTOPp->reset) | (IData)(vlTOPp->riscv__DOT__flush_d))) {
        vlTOPp->riscv__DOT__id_ex_regwrite_d = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->riscv__DOT__hazard_unit__DOT__lw_stall)))) {
            vlTOPp->riscv__DOT__id_ex_regwrite_d = 
                (1U & ((IData)(vlTOPp->riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals) 
                       >> 6U));
        }
    }
    vlTOPp->riscv__DOT__forward_operand_a_e = (((((IData)(vlTOPp->riscv__DOT__id_ex_rs1_d_reg) 
                                                  == (IData)(vlTOPp->riscv__DOT__ex_mem_rd_e)) 
                                                 & (IData)(vlTOPp->riscv__DOT__ex_mem_regwrite_e)) 
                                                & (0U 
                                                   != (IData)(vlTOPp->riscv__DOT__id_ex_rs1_d_reg)))
                                                ? 2U
                                                : (
                                                   ((((IData)(vlTOPp->riscv__DOT__id_ex_rs1_d_reg) 
                                                      == (IData)(vlTOPp->riscv__DOT__mem_wb_rd_w)) 
                                                     & (IData)(vlTOPp->riscv__DOT__mem_wb_regwrite_w)) 
                                                    & (0U 
                                                       != (IData)(vlTOPp->riscv__DOT__id_ex_rs1_d_reg)))
                                                    ? 1U
                                                    : 0U));
    vlTOPp->riscv__DOT__forward_operand_b_e = (((((IData)(vlTOPp->riscv__DOT__id_ex_rs2_d_reg) 
                                                  == (IData)(vlTOPp->riscv__DOT__ex_mem_rd_e)) 
                                                 & (IData)(vlTOPp->riscv__DOT__ex_mem_regwrite_e)) 
                                                & (0U 
                                                   != (IData)(vlTOPp->riscv__DOT__id_ex_rs2_d_reg)))
                                                ? 2U
                                                : (
                                                   ((((IData)(vlTOPp->riscv__DOT__id_ex_rs2_d_reg) 
                                                      == (IData)(vlTOPp->riscv__DOT__mem_wb_rd_w)) 
                                                     & (IData)(vlTOPp->riscv__DOT__mem_wb_regwrite_w)) 
                                                    & (0U 
                                                       != (IData)(vlTOPp->riscv__DOT__id_ex_rs2_d_reg)))
                                                    ? 1U
                                                    : 0U));
    if ((1U & (~ ((IData)(vlTOPp->reset) | (IData)(vlTOPp->riscv__DOT__flush_d))))) {
        if ((1U & (~ (IData)(vlTOPp->riscv__DOT__hazard_unit__DOT__lw_stall)))) {
            vlTOPp->riscv__DOT__id_ex_rd = (0x1fU & 
                                            (vlTOPp->riscv__DOT__if_id_instr 
                                             >> 7U));
        }
    }
    if (((IData)(vlTOPp->reset) | (IData)(vlTOPp->riscv__DOT__flush_d))) {
        vlTOPp->riscv__DOT__id_ex_result_src_d = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->riscv__DOT__hazard_unit__DOT__lw_stall)))) {
            vlTOPp->riscv__DOT__id_ex_result_src_d 
                = (3U & ((IData)(vlTOPp->riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals) 
                         >> 2U));
        }
    }
    if (((IData)(vlTOPp->reset) | (IData)(vlTOPp->riscv__DOT__flush_d))) {
        vlTOPp->riscv__DOT__id_ex_pc_plus_4 = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->riscv__DOT__hazard_unit__DOT__lw_stall)))) {
            vlTOPp->riscv__DOT__id_ex_pc_plus_4 = vlTOPp->riscv__DOT__if_id_pc_plus_4;
        }
    }
    vlTOPp->riscv__DOT__EX_unit__DOT__hazard_a = ((0U 
                                                   == (IData)(vlTOPp->riscv__DOT__forward_operand_a_e))
                                                   ? vlTOPp->riscv__DOT__id_ex_reg_a
                                                   : 
                                                  ((1U 
                                                    == (IData)(vlTOPp->riscv__DOT__forward_operand_a_e))
                                                    ? vlTOPp->riscv__DOT__mem_wb_alu_result_w
                                                    : 
                                                   ((2U 
                                                     == (IData)(vlTOPp->riscv__DOT__forward_operand_a_e))
                                                     ? vlTOPp->riscv__DOT__ex_mem_alu_result_e
                                                     : 0U)));
    if (vlTOPp->reset) {
        vlTOPp->__Vdly__riscv__DOT__if_id_pc = 0U;
        vlTOPp->riscv__DOT__if_id_pc_plus_4 = 4U;
        vlTOPp->riscv__DOT__if_id_instr = vlTOPp->riscv__DOT__IF_unit__DOT__instr_mem
            [0U];
        vlTOPp->__Vdly__riscv__DOT__IF_unit__DOT__next_pc = 4U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->riscv__DOT__hazard_unit__DOT__lw_stall)))) {
            vlTOPp->__Vdly__riscv__DOT__if_id_pc = vlTOPp->riscv__DOT__IF_unit__DOT__next_pc;
            vlTOPp->riscv__DOT__if_id_instr = vlTOPp->riscv__DOT__IF_unit__DOT__instr_mem
                [(0x1fU & (vlTOPp->riscv__DOT__IF_unit__DOT__next_pc 
                           >> 2U))];
            vlTOPp->riscv__DOT__if_id_pc_plus_4 = ((IData)(4U) 
                                                   + vlTOPp->riscv__DOT__IF_unit__DOT__next_pc);
            vlTOPp->__Vdly__riscv__DOT__IF_unit__DOT__next_pc 
                = ((IData)(vlTOPp->riscv__DOT__ex_mem_pc_src_e)
                    ? (vlTOPp->riscv__DOT__id_ex_pc 
                       + vlTOPp->riscv__DOT__id_ex_imm)
                    : ((IData)(4U) + vlTOPp->riscv__DOT__IF_unit__DOT__next_pc));
        }
    }
    vlTOPp->riscv__DOT__IF_unit__DOT__next_pc = vlTOPp->__Vdly__riscv__DOT__IF_unit__DOT__next_pc;
    vlTOPp->__Vtableidx1 = (0x7fU & vlTOPp->riscv__DOT__if_id_instr);
    vlTOPp->riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals 
        = vlTOPp->__Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals
        [vlTOPp->__Vtableidx1];
    if (((IData)(vlTOPp->reset) | (IData)(vlTOPp->riscv__DOT__flush_d))) {
        vlTOPp->riscv__DOT__id_ex_pc = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->riscv__DOT__hazard_unit__DOT__lw_stall)))) {
            vlTOPp->riscv__DOT__id_ex_pc = vlTOPp->riscv__DOT__if_id_pc;
        }
    }
    if (((IData)(vlTOPp->reset) | (IData)(vlTOPp->riscv__DOT__flush_d))) {
        vlTOPp->riscv__DOT__id_ex_imm = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->riscv__DOT__hazard_unit__DOT__lw_stall)))) {
            vlTOPp->riscv__DOT__id_ex_imm = vlTOPp->riscv__DOT__ID_unit__DOT__immediate_temp;
        }
    }
    vlTOPp->riscv__DOT__if_id_pc = vlTOPp->__Vdly__riscv__DOT__if_id_pc;
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
    vlTOPp->riscv__DOT__hazard_unit__DOT__lw_stall 
        = ((IData)(vlTOPp->riscv__DOT__id_ex_result_src_d) 
           & (((0x1fU & (vlTOPp->riscv__DOT__if_id_instr 
                         >> 0xfU)) == (IData)(vlTOPp->riscv__DOT__id_ex_rd)) 
              | ((0x1fU & (vlTOPp->riscv__DOT__if_id_instr 
                           >> 0x14U)) == (IData)(vlTOPp->riscv__DOT__id_ex_rd))));
    vlTOPp->riscv__DOT__EX_unit__DOT__operand_b = ((IData)(vlTOPp->riscv__DOT__id_ex_alu_src_d)
                                                    ? vlTOPp->riscv__DOT__id_ex_imm
                                                    : 
                                                   ((0U 
                                                     == (IData)(vlTOPp->riscv__DOT__forward_operand_b_e))
                                                     ? vlTOPp->riscv__DOT__id_ex_reg_b
                                                     : 
                                                    ((1U 
                                                      == (IData)(vlTOPp->riscv__DOT__forward_operand_b_e))
                                                      ? vlTOPp->riscv__DOT__mem_wb_alu_result_w
                                                      : 
                                                     ((2U 
                                                       == (IData)(vlTOPp->riscv__DOT__forward_operand_b_e))
                                                       ? vlTOPp->riscv__DOT__ex_mem_alu_result_e
                                                       : 0U))));
    vlTOPp->riscv__DOT__flush_d = ((~ (IData)(vlTOPp->reset)) 
                                   & (IData)(vlTOPp->riscv__DOT__ex_mem_pc_src_e));
    vlTOPp->riscv__DOT__EX_unit__DOT__alu_result_temp 
        = ((8U & (IData)(vlTOPp->riscv__DOT__id_ex_alu_control_d))
            ? ((4U & (IData)(vlTOPp->riscv__DOT__id_ex_alu_control_d))
                ? ((2U & (IData)(vlTOPp->riscv__DOT__id_ex_alu_control_d))
                    ? ((1U & (IData)(vlTOPp->riscv__DOT__id_ex_alu_control_d))
                        ? (0xfffff000U & (vlTOPp->riscv__DOT__EX_unit__DOT__operand_b 
                                          << 0xcU))
                        : 0U) : ((1U & (IData)(vlTOPp->riscv__DOT__id_ex_alu_control_d))
                                  ? (vlTOPp->riscv__DOT__EX_unit__DOT__hazard_a 
                                     >> (0x1fU & vlTOPp->riscv__DOT__EX_unit__DOT__operand_b))
                                  : (vlTOPp->riscv__DOT__EX_unit__DOT__hazard_a 
                                     + (0xfffff000U 
                                        & (vlTOPp->riscv__DOT__EX_unit__DOT__operand_b 
                                           << 0xcU)))))
                : ((2U & (IData)(vlTOPp->riscv__DOT__id_ex_alu_control_d))
                    ? 0U : ((1U & (IData)(vlTOPp->riscv__DOT__id_ex_alu_control_d))
                             ? 0U : (vlTOPp->riscv__DOT__EX_unit__DOT__hazard_a 
                                     - vlTOPp->riscv__DOT__EX_unit__DOT__operand_b))))
            : ((4U & (IData)(vlTOPp->riscv__DOT__id_ex_alu_control_d))
                ? ((2U & (IData)(vlTOPp->riscv__DOT__id_ex_alu_control_d))
                    ? ((1U & (IData)(vlTOPp->riscv__DOT__id_ex_alu_control_d))
                        ? (vlTOPp->riscv__DOT__EX_unit__DOT__hazard_a 
                           & vlTOPp->riscv__DOT__EX_unit__DOT__operand_b)
                        : (vlTOPp->riscv__DOT__EX_unit__DOT__hazard_a 
                           | vlTOPp->riscv__DOT__EX_unit__DOT__operand_b))
                    : ((1U & (IData)(vlTOPp->riscv__DOT__id_ex_alu_control_d))
                        ? (vlTOPp->riscv__DOT__EX_unit__DOT__hazard_a 
                           >> (0x1fU & vlTOPp->riscv__DOT__EX_unit__DOT__operand_b))
                        : (vlTOPp->riscv__DOT__EX_unit__DOT__hazard_a 
                           ^ vlTOPp->riscv__DOT__EX_unit__DOT__operand_b)))
                : ((2U & (IData)(vlTOPp->riscv__DOT__id_ex_alu_control_d))
                    ? ((1U & (IData)(vlTOPp->riscv__DOT__id_ex_alu_control_d))
                        ? ((vlTOPp->riscv__DOT__EX_unit__DOT__hazard_a 
                            < vlTOPp->riscv__DOT__EX_unit__DOT__operand_b)
                            ? 1U : 0U) : (VL_LTS_III(1,32,32, vlTOPp->riscv__DOT__EX_unit__DOT__hazard_a, vlTOPp->riscv__DOT__EX_unit__DOT__operand_b)
                                           ? 1U : 0U))
                    : ((1U & (IData)(vlTOPp->riscv__DOT__id_ex_alu_control_d))
                        ? (vlTOPp->riscv__DOT__EX_unit__DOT__hazard_a 
                           << (0x1fU & vlTOPp->riscv__DOT__EX_unit__DOT__operand_b))
                        : (vlTOPp->riscv__DOT__EX_unit__DOT__hazard_a 
                           + vlTOPp->riscv__DOT__EX_unit__DOT__operand_b)))));
    vlTOPp->riscv__DOT__ex_mem_zero_flag_e = (0U == vlTOPp->riscv__DOT__EX_unit__DOT__alu_result_temp);
    vlTOPp->riscv__DOT__ex_mem_pc_src_e = ((((4U & (IData)(vlTOPp->riscv__DOT__id_ex_branch_control_d))
                                              ? ((2U 
                                                  & (IData)(vlTOPp->riscv__DOT__id_ex_branch_control_d))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->riscv__DOT__id_ex_branch_control_d))
                                                   ? 
                                                  (vlTOPp->riscv__DOT__EX_unit__DOT__hazard_a 
                                                   >= vlTOPp->riscv__DOT__EX_unit__DOT__operand_b)
                                                   : 
                                                  (vlTOPp->riscv__DOT__EX_unit__DOT__hazard_a 
                                                   < vlTOPp->riscv__DOT__EX_unit__DOT__operand_b))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->riscv__DOT__id_ex_branch_control_d))
                                                   ? 
                                                  VL_GTES_III(1,32,32, vlTOPp->riscv__DOT__EX_unit__DOT__hazard_a, vlTOPp->riscv__DOT__EX_unit__DOT__operand_b)
                                                   : 
                                                  VL_LTS_III(1,32,32, vlTOPp->riscv__DOT__EX_unit__DOT__hazard_a, vlTOPp->riscv__DOT__EX_unit__DOT__operand_b)))
                                              : ((~ 
                                                  ((IData)(vlTOPp->riscv__DOT__id_ex_branch_control_d) 
                                                   >> 1U)) 
                                                 & ((1U 
                                                     & (IData)(vlTOPp->riscv__DOT__id_ex_branch_control_d))
                                                     ? 
                                                    (vlTOPp->riscv__DOT__EX_unit__DOT__hazard_a 
                                                     != vlTOPp->riscv__DOT__EX_unit__DOT__operand_b)
                                                     : 
                                                    (vlTOPp->riscv__DOT__EX_unit__DOT__hazard_a 
                                                     == vlTOPp->riscv__DOT__EX_unit__DOT__operand_b)))) 
                                            & (IData)(vlTOPp->riscv__DOT__id_ex_branch_d)) 
                                           | (IData)(vlTOPp->riscv__DOT__id_ex_jump_d));
    vlTOPp->riscv__DOT__flush_e = ((IData)(vlTOPp->riscv__DOT__hazard_unit__DOT__lw_stall) 
                                   | (IData)(vlTOPp->riscv__DOT__ex_mem_pc_src_e));
}

void Vriscv::_eval(Vriscv__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv::_eval\n"); );
    Vriscv* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    if ((((~ (IData)(vlTOPp->clk)) & (IData)(vlTOPp->__Vclklast__TOP__clk)) 
         | ((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->__Vm_traceActivity[2U] = 1U;
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
        vlTOPp->__Vm_traceActivity[3U] = 1U;
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

VL_INLINE_OPT QData Vriscv::_change_request(Vriscv__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv::_change_request\n"); );
    Vriscv* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vriscv::_change_request_1(Vriscv__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv::_change_request_1\n"); );
    Vriscv* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vriscv::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG

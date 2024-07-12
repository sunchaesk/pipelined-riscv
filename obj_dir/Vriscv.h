// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VRISCV_H_
#define _VRISCV_H_  // guard

#include "verilated_heavy.h"

//==========

class Vriscv__Syms;
class Vriscv_VerilatedVcd;


//----------

VL_MODULE(Vriscv) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*4:0*/ riscv__DOT__id_ex_rd;
    CData/*0:0*/ riscv__DOT__id_ex_regwrite_d;
    CData/*1:0*/ riscv__DOT__id_ex_result_src_d;
    CData/*0:0*/ riscv__DOT__id_ex_memwrite_d;
    CData/*0:0*/ riscv__DOT__id_ex_jump_d;
    CData/*0:0*/ riscv__DOT__id_ex_branch_d;
    CData/*3:0*/ riscv__DOT__id_ex_alu_control_d;
    CData/*2:0*/ riscv__DOT__id_ex_branch_control_d;
    CData/*0:0*/ riscv__DOT__id_ex_alu_src_d;
    CData/*4:0*/ riscv__DOT__id_ex_rs1_d_reg;
    CData/*4:0*/ riscv__DOT__id_ex_rs2_d_reg;
    CData/*0:0*/ riscv__DOT__ex_mem_zero_flag_e;
    CData/*4:0*/ riscv__DOT__ex_mem_rd_e;
    CData/*0:0*/ riscv__DOT__ex_mem_regwrite_e;
    CData/*1:0*/ riscv__DOT__ex_mem_result_src_e;
    CData/*0:0*/ riscv__DOT__ex_mem_memwrite_e;
    CData/*0:0*/ riscv__DOT__ex_mem_pc_src_e;
    CData/*0:0*/ riscv__DOT__mem_wb_regwrite_w;
    CData/*1:0*/ riscv__DOT__mem_wb_result_src_w;
    CData/*4:0*/ riscv__DOT__mem_wb_rd_w;
    CData/*0:0*/ riscv__DOT__wb_regwrite;
    CData/*4:0*/ riscv__DOT__wb_rd;
    CData/*0:0*/ riscv__DOT__zero_flag;
    CData/*0:0*/ riscv__DOT__flush_d;
    CData/*0:0*/ riscv__DOT__flush_e;
    CData/*1:0*/ riscv__DOT__forward_operand_a_e;
    CData/*1:0*/ riscv__DOT__forward_operand_b_e;
    CData/*6:0*/ riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals;
    CData/*0:0*/ riscv__DOT__hazard_unit__DOT__lw_stall;
    IData/*31:0*/ riscv__DOT__if_id_instr;
    IData/*31:0*/ riscv__DOT__if_id_pc;
    IData/*31:0*/ riscv__DOT__if_id_pc_plus_4;
    IData/*31:0*/ riscv__DOT__id_ex_pc;
    IData/*31:0*/ riscv__DOT__id_ex_reg_a;
    IData/*31:0*/ riscv__DOT__id_ex_reg_b;
    IData/*31:0*/ riscv__DOT__id_ex_imm;
    IData/*31:0*/ riscv__DOT__id_ex_pc_plus_4;
    IData/*31:0*/ riscv__DOT__ex_mem_alu_result_e;
    IData/*31:0*/ riscv__DOT__ex_mem_writedata_e;
    IData/*31:0*/ riscv__DOT__ex_mem_pc_plus_4_e;
    IData/*31:0*/ riscv__DOT__mem_wb_readdata_w;
    IData/*31:0*/ riscv__DOT__mem_wb_alu_result_w;
    IData/*31:0*/ riscv__DOT__mem_wb_pc_plus_4_w;
    IData/*31:0*/ riscv__DOT__wb_result;
    IData/*31:0*/ riscv__DOT__alu_result;
    IData/*31:0*/ riscv__DOT__IF_unit__DOT__next_pc;
    IData/*31:0*/ riscv__DOT__ID_unit__DOT__immediate_temp;
    IData/*31:0*/ riscv__DOT__ID_unit__DOT__i;
    IData/*31:0*/ riscv__DOT__EX_unit__DOT__operand_b;
    IData/*31:0*/ riscv__DOT__EX_unit__DOT__alu_result_temp;
    IData/*31:0*/ riscv__DOT__EX_unit__DOT__hazard_a;
    IData/*31:0*/ riscv__DOT__IF_unit__DOT__instr_mem[32];
    IData/*31:0*/ riscv__DOT__ID_unit__DOT__reg_array[32];
    IData/*31:0*/ riscv__DOT__MEM_unit__DOT__mem_array[32];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*6:0*/ __Vtableidx1;
    CData/*4:0*/ __Vdlyvdim0__riscv__DOT__MEM_unit__DOT__mem_array__v0;
    CData/*0:0*/ __Vdlyvset__riscv__DOT__MEM_unit__DOT__mem_array__v0;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__reset;
    IData/*31:0*/ __Vdly__riscv__DOT__if_id_pc;
    IData/*31:0*/ __Vdly__riscv__DOT__IF_unit__DOT__next_pc;
    IData/*31:0*/ __Vdlyvval__riscv__DOT__MEM_unit__DOT__mem_array__v0;
    CData/*0:0*/ __Vm_traceActivity[4];
    static CData/*6:0*/ __Vtable1_riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals[128];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vriscv__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vriscv);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vriscv(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vriscv();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
    static void _eval_initial_loop(Vriscv__Syms* __restrict vlSymsp);
    void __Vconfigure(Vriscv__Syms* symsp, bool first);
  private:
    static QData _change_request(Vriscv__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vriscv__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vriscv__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vriscv__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vriscv__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(Vriscv__Syms* __restrict vlSymsp);
    static void _sequent__TOP__2(Vriscv__Syms* __restrict vlSymsp);
    static void _sequent__TOP__4(Vriscv__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(Vriscv__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard

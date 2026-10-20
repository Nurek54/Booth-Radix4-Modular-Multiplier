// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VBoothRadix4.h for the primary calling header

#ifndef VERILATED_VBOOTHRADIX4___024ROOT_H_
#define VERILATED_VBOOTHRADIX4___024ROOT_H_  // guard

#include "verilated.h"


class VBoothRadix4__Syms;

class alignas(VL_CACHE_LINE_BYTES) VBoothRadix4___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    CData/*0:0*/ BoothRadix4__DOT__q_add;
    CData/*0:0*/ BoothRadix4__DOT__q_reset;
    VL_OUT8(done,0,0);
    VL_IN8(n_reset,0,0);
    VL_IN8(start,0,0);
    CData/*1:0*/ BoothRadix4__DOT__state_reg;
    CData/*1:0*/ BoothRadix4__DOT__state_next;
    CData/*4:0*/ BoothRadix4__DOT__q_reg;
    CData/*4:0*/ BoothRadix4__DOT__q_next;
    CData/*0:0*/ BoothRadix4__DOT__result_reg;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    VL_IN(mplier,17,0);
    VL_IN(mcand,17,0);
    IData/*17:0*/ BoothRadix4__DOT__mcand_reg;
    IData/*17:0*/ BoothRadix4__DOT__mcand_next;
    IData/*31:0*/ __VactIterCount;
    VL_OUT64(product,35,0);
    QData/*37:0*/ BoothRadix4__DOT__prod_reg;
    QData/*37:0*/ BoothRadix4__DOT__prod_next;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    VBoothRadix4__Syms* const vlSymsp;

    // CONSTRUCTORS
    VBoothRadix4___024root(VBoothRadix4__Syms* symsp, const char* v__name);
    ~VBoothRadix4___024root();
    VL_UNCOPYABLE(VBoothRadix4___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard

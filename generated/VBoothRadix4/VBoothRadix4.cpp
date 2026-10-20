// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VBoothRadix4__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VBoothRadix4::VBoothRadix4(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VBoothRadix4__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , done{vlSymsp->TOP.done}
    , n_reset{vlSymsp->TOP.n_reset}
    , start{vlSymsp->TOP.start}
    , mplier{vlSymsp->TOP.mplier}
    , mcand{vlSymsp->TOP.mcand}
    , product{vlSymsp->TOP.product}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VBoothRadix4::VBoothRadix4(const char* _vcname__)
    : VBoothRadix4(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VBoothRadix4::~VBoothRadix4() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VBoothRadix4___024root___eval_debug_assertions(VBoothRadix4___024root* vlSelf);
#endif  // VL_DEBUG
void VBoothRadix4___024root___eval_static(VBoothRadix4___024root* vlSelf);
void VBoothRadix4___024root___eval_initial(VBoothRadix4___024root* vlSelf);
void VBoothRadix4___024root___eval_settle(VBoothRadix4___024root* vlSelf);
void VBoothRadix4___024root___eval(VBoothRadix4___024root* vlSelf);

void VBoothRadix4::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VBoothRadix4::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VBoothRadix4___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VBoothRadix4___024root___eval_static(&(vlSymsp->TOP));
        VBoothRadix4___024root___eval_initial(&(vlSymsp->TOP));
        VBoothRadix4___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VBoothRadix4___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VBoothRadix4::eventsPending() { return false; }

uint64_t VBoothRadix4::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VBoothRadix4::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VBoothRadix4___024root___eval_final(VBoothRadix4___024root* vlSelf);

VL_ATTR_COLD void VBoothRadix4::final() {
    VBoothRadix4___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VBoothRadix4::hierName() const { return vlSymsp->name(); }
const char* VBoothRadix4::modelName() const { return "VBoothRadix4"; }
unsigned VBoothRadix4::threads() const { return 1; }
void VBoothRadix4::prepareClone() const { contextp()->prepareClone(); }
void VBoothRadix4::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> VBoothRadix4::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VBoothRadix4___024root__trace_decl_types(VerilatedVcd* tracep);

void VBoothRadix4___024root__trace_init_top(VBoothRadix4___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VBoothRadix4___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VBoothRadix4___024root*>(voidSelf);
    VBoothRadix4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    VBoothRadix4___024root__trace_decl_types(tracep);
    VBoothRadix4___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void VBoothRadix4___024root__trace_register(VBoothRadix4___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VBoothRadix4::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VBoothRadix4::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VBoothRadix4___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}

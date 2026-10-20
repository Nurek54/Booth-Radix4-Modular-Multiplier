#include "hw/BoothRadix4Sim.h"

#include "VBoothRadix4.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

#include <stdexcept>

namespace hw {

static int64_t signExtend(uint64_t value, int bits) {
    const uint64_t sign = uint64_t(1) << (bits - 1);
    value &= (uint64_t(1) << bits) - 1;
    return int64_t((value ^ sign) - sign);
}

BoothRadix4Sim::BoothRadix4Sim(const std::string& vcdFile) : context(new VerilatedContext) {
    if (!vcdFile.empty()) context->traceEverOn(true);
    top.reset(new VBoothRadix4(context.get()));
    if (!vcdFile.empty()) {
        trace.reset(new VerilatedVcdC);
        top->trace(trace.get(), 99);
        trace->open(vcdFile.c_str());
    }
    // Reset synchroniczny (aktywny stanem niskim) przez dwa cykle
    top->clk = 0;
    top->start = 0;
    top->mplier = 0;
    top->mcand = 0;
    top->n_reset = 0;
    tick();
    tick();
    top->n_reset = 1;
    tick();
}

BoothRadix4Sim::~BoothRadix4Sim() {
    if (trace) trace->close();
    top->final();
}

void BoothRadix4Sim::halfCycle(int clk) {
    top->clk = clk;
    top->eval();
    if (trace) trace->dump(time);
    time += 5;  // okres zegara 10 jednostek
}

void BoothRadix4Sim::tick() {
    halfCycle(0);
    halfCycle(1);
}

HwResult BoothRadix4Sim::multiply(int64_t mplier, int64_t mcand) {
    if (mplier < MIN_VALUE || mplier > MAX_VALUE || mcand < MIN_VALUE || mcand > MAX_VALUE)
        throw std::out_of_range("argument poza zakresem 18-bitowej liczby ze znakiem");
    const uint64_t mask = (uint64_t(1) << WIDTH) - 1;
    top->mplier = uint32_t(uint64_t(mplier) & mask);  // wejscia modelu musza miec wyzerowane starsze bity
    top->mcand = uint32_t(uint64_t(mcand) & mask);

    top->start = 1;
    tick();  // IDLE -> BUSY, zaladowanie argumentow
    top->start = 0;
    int cycles = 1;
    while (!top->done) {  // N/2 krokow Bootha
        tick();
        if (++cycles > 4 * WIDTH) throw std::runtime_error("modul nie zglosil done");
    }
    tick();  // na zboczu z done = 1 wynik trafia do rejestru product
    ++cycles;
    return {signExtend(top->product, 2 * WIDTH), cycles};
}

}  // namespace hw

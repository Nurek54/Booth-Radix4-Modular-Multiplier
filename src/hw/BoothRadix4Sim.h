#ifndef BOOTH_RADIX4_SIM_H
#define BOOTH_RADIX4_SIM_H

#include <cstdint>
#include <memory>
#include <string>

class VerilatedContext;
class VerilatedVcdC;
class VBoothRadix4;

namespace hw {

// Szerokosc argumentow modulu BoothRadix4 (parametr N w rtl/BoothRadix4.v)
constexpr int WIDTH = 18;
constexpr int64_t MIN_VALUE = -(int64_t(1) << (WIDTH - 1));
constexpr int64_t MAX_VALUE = (int64_t(1) << (WIDTH - 1)) - 1;

struct HwResult {
    int64_t product;  // wynik 2*WIDTH bitow, rozszerzony ze znakiem
    int cycles;       // cykle zegara od podania start do wyniku na wyjsciu product
};

// Testbench w C++: model Verilatora modulu BoothRadix4 sterowany zegarem.
// Jesli podano plik VCD, zapisuje do niego przebiegi wszystkich sygnalow.
class BoothRadix4Sim {
public:
    explicit BoothRadix4Sim(const std::string& vcdFile = "");
    ~BoothRadix4Sim();

    HwResult multiply(int64_t mplier, int64_t mcand);

private:
    void halfCycle(int clk);
    void tick();

    std::unique_ptr<VerilatedContext> context;
    std::unique_ptr<VBoothRadix4> top;
    std::unique_ptr<VerilatedVcdC> trace;
    uint64_t time = 0;
};

}  // namespace hw

#endif

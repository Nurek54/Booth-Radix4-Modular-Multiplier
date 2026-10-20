#include "modulo/Modulo.h"

#include <stdexcept>

Modulo::Modulo(int n) : n(n) {
    if (n < 2 || n > 40) throw std::invalid_argument("n musi byc z przedzialu 2..40");
    modValue = (int64_t(1) << n) - 3;
}

int64_t Modulo::applyModulo(int64_t value) const {
    int64_t result = value % modValue;
    if (result < 0) result += modValue;  // reszta z % ma znak dzielnej
    return result;
}

int64_t Modulo::reduce(int64_t value, int* folds) const {
    const uint64_t low = (uint64_t(1) << n) - 1;
    uint64_t u = value < 0 ? uint64_t(0) - uint64_t(value) : uint64_t(value);  // |x|
    int k = 0;
    while (u >> n) {
        u = 3 * (u >> n) + (u & low);
        ++k;
    }
    while (u >= uint64_t(modValue)) u -= uint64_t(modValue);  // u < 2^n = M + 3: raz dla n > 2 (dla n = 2 M = 1)
    if (folds) *folds = k;
    if (value < 0 && u != 0) u = uint64_t(modValue) - u;  // -x mod M
    return int64_t(u);
}

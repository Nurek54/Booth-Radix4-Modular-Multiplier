#ifndef MODULO_H
#define MODULO_H

#include <cstdint>

// Reszta z dzielenia przez M = 2^n - 3, wynik zawsze w przedziale [0, M)
class Modulo {
public:
    explicit Modulo(int n);  // 2 <= n <= 40

    int64_t modulus() const { return modValue; }
    int64_t applyModulo(int64_t value) const;  // operator % (wynik odniesienia)

    // Redukcja bez dzielenia, jak w ukladzie: 2^n = 3 (mod M), wiec x = H*2^n + L daje 3H + L.
    // Powtarzana, az wynik ma n bitow, na koncu jedno odejmowanie M (dla n > 2).
    int64_t reduce(int64_t value, int* folds = nullptr) const;

private:
    int n;
    int64_t modValue;
};

#endif

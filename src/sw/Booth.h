#ifndef BOOTH_H
#define BOOTH_H

#include <cstdint>
#include <vector>

// Klasyczny algorytm Bootha (radix-2) na wektorach bitow, n iteracji dla n-bitowych argumentow.
// Wynik ma 2n bitow: rejestr A (starsza polowa) i Q (mlodsza polowa). A i M maja n+1 bitow,
// bo dla mnoznej -2^(n-1) wartosc -M = 2^(n-1) nie miesci sie w n bitach ze znakiem.
class Booth {
public:
    Booth(int64_t M, int64_t Q, int n = 18);  // mnozna, mnoznik, liczba bitow
    int64_t multiply();                       // wynik 2n bitow ze znakiem
    int iterations() const { return n; }

private:
    std::vector<int> addBinary(const std::vector<int>& a, const std::vector<int>& b);  // dodawanie modulo 2^n
    std::vector<int> negateBinary(const std::vector<int>& a);                         // dopelnienie do dwoch
    void rightShift(std::vector<int>& A, std::vector<int>& Q, int& Q_1);              // przesuniecie arytmetyczne A:Q:Q_1

    int n;                   // liczba bitow argumentow
    std::vector<int> A;      // czesciowy wynik (starsza polowa), n+1 bitow
    std::vector<int> M_bin;  // mnozna, n+1 bitow
    std::vector<int> Q_bin;  // mnoznik, po n krokach mlodsza polowa wyniku
    std::vector<int> M_neg;  // -mnozna
    int Q_1;                 // bit Q_-1
};

#endif

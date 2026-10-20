#include "sw/Booth.h"

#include "util/BinaryUtils.h"

// Wektory bitow sa zapisane od najstarszego bitu (indeks 0) do najmlodszego (indeks n-1)
Booth::Booth(int64_t M, int64_t Q, int n) : n(n) {
    A.assign(n + 1, 0);
    M_bin = BinaryUtils::toBinary(M, n + 1);
    Q_bin = BinaryUtils::toBinary(Q, n);
    M_neg = negateBinary(M_bin);
    Q_1 = 0;
}

std::vector<int> Booth::addBinary(const std::vector<int>& a, const std::vector<int>& b) {
    std::vector<int> result(a.size(), 0);
    int carry = 0;
    for (int i = int(a.size()) - 1; i >= 0; i--) {
        int sum = a[i] + b[i] + carry;
        result[i] = sum % 2;
        carry = sum / 2;
    }
    return result;  // przeniesienie z najstarszego bitu jest pomijane
}

std::vector<int> Booth::negateBinary(const std::vector<int>& a) {
    std::vector<int> result(a.size(), 0);
    std::vector<int> one(a.size(), 0);
    one[a.size() - 1] = 1;
    for (size_t i = 0; i < a.size(); i++) result[i] = a[i] == 0 ? 1 : 0;
    return addBinary(result, one);
}

void Booth::rightShift(std::vector<int>& A, std::vector<int>& Q, int& Q_1) {
    Q_1 = Q[Q.size() - 1];
    for (size_t i = Q.size() - 1; i > 0; i--) Q[i] = Q[i - 1];
    Q[0] = A[A.size() - 1];
    for (size_t i = A.size() - 1; i > 0; i--) A[i] = A[i - 1];  // A[0] (znak) zostaje: przesuniecie arytmetyczne
}

int64_t Booth::multiply() {
    for (int i = 0; i < n; i++) {
        if (Q_bin[n - 1] == 1 && Q_1 == 0) {  // para 10: A = A - M
            A = addBinary(A, M_neg);
        } else if (Q_bin[n - 1] == 0 && Q_1 == 1) {  // para 01: A = A + M
            A = addBinary(A, M_bin);
        }
        rightShift(A, Q_bin, Q_1);
    }
    // Wynik to A:Q (wczesniej czytany byl tylko Q, czyli mlodsze bity, a A i M mialy po 32 bity)
    std::vector<int> product(A);
    product.insert(product.end(), Q_bin.begin(), Q_bin.end());
    return BinaryUtils::binaryToDecimal(product);
}

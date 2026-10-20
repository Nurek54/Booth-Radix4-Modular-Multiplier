#ifndef BINARY_UTILS_H
#define BINARY_UTILS_H

#include <cstdint>
#include <string>
#include <vector>

namespace BinaryUtils {
// Liczba -> wektor `size` bitow w kodzie U2, od najstarszego bitu
std::vector<int> toBinary(int64_t num, int size);
// Wektor bitow w kodzie U2 (od najstarszego) -> liczba ze znakiem, do 63 bitow
int64_t binaryToDecimal(const std::vector<int>& binary);
// Liczba -> napis `bits` znakow 0/1 w kodzie U2
std::string toBinaryString(int64_t value, int bits);
}  // namespace BinaryUtils

#endif

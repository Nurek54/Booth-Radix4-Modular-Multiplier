#include "util/BinaryUtils.h"

namespace BinaryUtils {

std::vector<int> toBinary(int64_t num, int size) {
    std::vector<int> bin(size, 0);
    for (int i = 0; i < size; i++) bin[size - 1 - i] = int((uint64_t(num) >> i) & 1);
    return bin;
}

int64_t binaryToDecimal(const std::vector<int>& binary) {
    int64_t result = 0;
    for (int bit : binary) result = int64_t(uint64_t(result) << 1) | bit;
    const int n = int(binary.size());
    if (n < 64 && !binary.empty() && binary[0] == 1) result -= int64_t(1) << n;  // liczba ujemna
    return result;
}

std::string toBinaryString(int64_t value, int bits) {
    std::string s;
    for (int i = bits - 1; i >= 0; i--) s += ((uint64_t(value) >> i) & 1) ? '1' : '0';
    return s;
}

}  // namespace BinaryUtils

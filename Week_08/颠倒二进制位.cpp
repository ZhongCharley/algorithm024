//code190
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            res <<= 1;
            // n&1判断最后一位是1是0， | 给res的最后一个位赋值
            res |= n & 1;
            n >>= 1;
        }
        return res;
    }
};
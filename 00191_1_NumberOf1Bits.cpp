/**
 * 46.57% 93.66%
 */

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int bits = 0;
        int mask = 1;
        for (int i = 0; i < 32; i++) {
            if ((n & mask) != 0) {
                bits++;
            }
            n >>= 1;
        }
        return bits;
    }
};

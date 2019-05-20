#include <algorithm>
class Solution {
public:
    bool isPowerOfThree(int n) {
        int res[] = {1,        3,        9,         27,        81,
                     243,      729,      2187,      6561,      19683,
                     59049,    177147,   531441,    1594323,   4782969,
                     14348907, 43046721, 129140163, 387420489, 1162261467};
        return std::binary_search(res, res + 20, n);
    }
};

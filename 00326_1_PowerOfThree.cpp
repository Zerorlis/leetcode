/**
 * @file 00326_1_PowerOfThree.cpp
 * @brief 思路，每次除以3，除到即可
 * @author Zerorlis
 * @version 0.1
 * @date 2019-05-19
 */

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1) return false;
        if (n == 1) return true;
        if (n % 3 != 0 || n == 0 || n == 2) return false;
        return isPowerOfThree(n / 3);
    }
};

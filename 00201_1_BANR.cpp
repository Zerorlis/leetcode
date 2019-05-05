/**
 * @file 00201_1_BANR.cpp
 * @brief
 * 思路，m(m-1)的按位与，会把前面的公共串留下，剩下的弄0，找到mn之间所有数字的公共串就行了
 * @author Zerorlis
 * @version 0.1
 * @date 2019-04-14
 */

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int count = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            ++count;
        }
        return m << count;
    }
};

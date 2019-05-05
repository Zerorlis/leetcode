/**
 * @file 00070_1_cs.cpp
 * @brief 打算用动态规划,f(m) = f(m-1)+f(m-2)
 * @author Zerorlis
 * @version 0.1
 * @date 2019-04-09
 */
#include <vector>

using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        vector<int> res(n, 0);
        res[0] = 1;
        res[1] = 2;
        for (int i = 2; i < n; i++) {
            res[i] = res[i - 1] + res[i - 2];
        }
        return res[n - 1];
    }
};

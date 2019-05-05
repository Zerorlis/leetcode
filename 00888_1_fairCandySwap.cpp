/**
 * @file 00888_1_fairCandySwap.cpp
 * @brief 利用了bitset来加快速度，空间时间
 * @author Zerorlis
 * @version 0.
 * @date 2019-04-19
 */
#include <bitset>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        bitset<100001> bs;
        int sumA = accumulate(A.begin(), A.end(), 0);
        int sumB = 0;
        for (auto b : B) {
            sumB += b;
            bs.set(b);  // b位设置为1
        }
        int diff = (sumA - sumB) / 2;
        for (auto a : A) {
            int x = a - diff;
            if (x > 0 && x < 100001 && bs.test(x)) {
                return {a, x};
            }
        }
        return {};
    }
};

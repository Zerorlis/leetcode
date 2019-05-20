/**
 * @file 00891_SumOfSW.cpp
 * @brief 超时，目测算幂的次数太多，虽然快速幂但是不建议这样反复计算
 * @author Zerorlis
 * @version 0.1
 * @date 2019-05-20
 */

#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        long res = 0;
        sort(A.begin(), A.end());
        for (int i = 0; i < A.size(); i++) {
            for (int j = i + 1; j < A.size(); j++) {
                res += (A[j] - A[i]) * pow(2, j - i - 1, 1000000007);
                res %= 1000000007;
            }
        }
        return res;
    }
    long pow(long a, int b, int mo) {
        long res = 1;
        a %= mo;
        while (b) {
            if (b & 1) res = res * a % mo;
            b >>= 1;  // 除以2
            a = (a * a) % mo;
        }
        return res;
    }
};

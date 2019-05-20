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
        int MOD = 1000000007;
        int N = A.size();
        sort(A.begin(), A.end());
        vector<long> pow2(N);
        pow2[0] = 1;
        for (int i = 1; i < N; ++i) pow2[i] = pow2[i - 1] * 2 % MOD;

        long ans = 0;
        for (int i = 0; i < N; ++i)
            ans = (ans + (pow2[i] - pow2[N - 1 - i]) * A[i]) % MOD;

        return (int)ans;
    }
};

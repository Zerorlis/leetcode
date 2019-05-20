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
        for (int i = 0; i <= A.size() - 2;
             i++) {  // i是两个数字之间拥有数字的数量
            int temp = 0;
            for (int j = 0; j + i + 1 < A.size(); j++) {
                temp += A[j + i + 1] - A[j];
            }

            res += temp * pow(2, i, 1000000007);
            res %= 1000000007;
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

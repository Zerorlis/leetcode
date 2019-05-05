/**
 * @file 00730_1_CDPS.cpp
 * @brief 动态规划问题，[i][j] 代表ij之间回文子序列的个数
 * @author Zerorlis
 * @version 0.1
 * @date 2019-04-10
 */
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int countPalindromicSubsequences(string S) {
        vector<vector<int>> m(S.size(), vector<int>(S.size(), 0));
        for (int i = 0; i < S.size(); i++) m[i][i] = 1;
        return count(m, S, 0, S.size() - 1);
    }

    int count(vector<vector<int>>& m, string& S, int begin, int end) {
        if (begin > end) return 0;
        if (m[begin][end] != 0) return m[begin][end];
        // 接下来要开始做动态规划了，分解为比较小的部分
        long sum;
        if (S[begin] != S[end]) {
            sum = count(m, S, begin + 1, end) + count(m, S, begin, end - 1) -
                  count(m, S, begin + 1, end - 1);
        } else {
            // axxxxxa 这样的格式，要检测xxxx中有没有a
            int i = begin + 1;
            int j = end - 1;
            while (S[i] != S[begin]) ++i;
            while (S[j] != S[end]) --j;
            if (i > j) {
                //代表各自走到头了,没找到a
                sum = count(m, S, begin + 1, end - 1) * 2 + 2;
            } else if (i == j) {
                sum = count(m, S, begin + 1, end - 1) * 2 + 1;
            } else {
                sum = count(m, S, begin + 1, end - 1) * 2 -
                      count(m, S, i + 1, j - 1);
            }
        }
        m[begin][end] = (sum + 1000000007) % 1000000007;
        return m[begin][end];
    }
};

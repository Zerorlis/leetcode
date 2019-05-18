/**
 * @file 00856_1_SP.cpp
 * @brief 思路，(()(())) = (())+((())), 记录层数，当遇到（）的时候，在结果上相加
 * @author Zerorlis
 * @version 0.1
 * @date 2019-05-18
 */
#include <string>
using namespace std;
class Solution {
public:
    int scoreOfParentheses(string S) {
        int res = 0, depth = 0;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '(') depth++;
            if (S[i] == ')') depth--;
            if (S[i] == ')' && S[i - 1] == '(') res += (1 << depth);
        }
        return res;
    }
};

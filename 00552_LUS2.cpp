/**
 * @file 00552_LUS2.cpp
 * @brief
 * 思路，先做一次按长度降序，从最长开始，如果找到一个不是这个同长度和之前的的子序列，就找到了这个长度.
 * @author Zerorlis
 * @version 0.1
 * @date 2019-05-17
 */
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool isSubsequence(string& a, string& b) {
        // a 是不是b的是一个子序列
        auto i = a.begin();
        auto j = b.begin();
        while (j != b.end() && i != a.end()) {
            if (*i == *j) {
                i++;
            }
            j++;
        }
        return i == a.end();
    }
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(),
             [](string& a, string& b) { return a.size() > b.size(); });
        for (int i = 0; i < strs.size(); i++) {
            bool isres = true;
            for (int j = 0; j < strs.size() && strs[j].size() >= strs[i].size();
                 j++) {
                if (i != j && isSubsequence(strs[i], strs[j])) {
                    isres = false;
                    break;
                }
            }
            if (isres) return strs[i].size();
        }
        return -1;
    }
};

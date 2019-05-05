/**
 * @file 01002_1_FCC.cpp
 * @brief
 * 思路，打算暴力查找，统计每个string26个字母出现的次数，然后在每个字母中找最小值就行
 * @author Zerorlis
 * @version 0.1
 * @date 2019-04-13
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<vector<int>> v(26, vector<int>(A.size(), 0));
        for (int i = 0; i < A.size(); i++) {
            for (char c : A[i]) {
                ++v[c - 'a'][i];
            }
        }
        vector<string> res;
        for (int i = 0; i < 26; i++) {
            int time = *min_element(v[i].begin(), v[i].end());
            for (int j = 0; j < time; j++) {
                res.push_back(string(1, 'a' + i));
            }
        }
        return res;
    }
};

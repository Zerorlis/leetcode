/**
 * @file 00942_1_DISM.cpp
 * @brief 使用一个双头的队列，i就出头的位置，d就处尾巴的位置,92%,0.5%
 * @author Zerorlis
 * @version 0.1
 * @date 2019-04-09
 */
#include <deque>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> res;
        deque<int> range;
        res.reserve(S.size() + 1);
        for (int i = 0; i < S.size() + 1; i++) {
            range.push_back(i);
        }
        for (auto p = S.begin(); p != S.end(); p++) {
            if (*p == 'D') {
                res.push_back(range.back());
                range.pop_back();
            } else {
                res.push_back(range.front());
                range.pop_front();
            }
        }
        res.push_back(range.front());
        return res;
    }
};

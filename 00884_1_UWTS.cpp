/**
 * @file 00884_1_UWTS.cpp
 * @brief 失败了，没有检查两句话里面重复的单词
 * @author Zerorlis
 * @version 0.1
 * @date 2019-05-07
 */
#include <algorithm>
#include <iterator>
#include <set>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        set<string> s1 = split(A);
        set<string> s2 = split(B);
        vector<string> res;
        set_symmetric_difference(s1.begin(), s1.end(), s2.begin(), s2.end(),
                                 inserter(res, res.begin()));
        return res;
    }
    set<string> split(const string& s) {
        set<string> result;
        auto p2 = s.find(' ', 0);
        auto p1 = 0;
        while (p2 != string::npos) {
            result.insert(s.substr(p1, p2 - p1));
            p1 = p2 + 1;  // 要把找到的第一个空格给去掉
            p2 = s.find(' ', p1);
        }
        // 要添加最后一组的词
        if (p1 != s.size()) result.insert(s.substr());
        return result;
    }
};

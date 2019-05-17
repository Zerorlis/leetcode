/**
 * @file 00884_1_UWTS.cpp
 * @brief 失败了，没有检查两句话里面重复的单词
 * @author Zerorlis
 * @version 0.1
 * @date 2019-05-07
 */
#include <algorithm>
#include <iterator>
#include <map>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        string s = A + " " + B;
        map<string, int> result;
        vector<string> res;
        auto p2 = s.find(' ', 0);
        auto p1 = 0;
        while (p2 != string::npos) {
            result[s.substr(p1, p2 - p1)]++;
            p1 = p2 + 1;  // 要把找到的第一个空格给去掉
            p2 = s.find(' ', p1);
        }
        if (p1 != s.size()) {
            result[s.substr(p1)]++;
        }
        for_each(result.begin(), result.end(), [&res](pair<string, int> p) {
            if (p.second == 1) res.push_back(p.first);
        });
        return res;

        // 要添加最后一组的词
    }
};

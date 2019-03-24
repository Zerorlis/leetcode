/**
 * 超时
 * */
#include <algorithm>

#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        for (auto i = s.begin(); i != s.end(); i++) {
            for (auto j = i + 1; j != s.end() + 1; j++) {
                if (noRepet(i, j)) {
                    maxLength =
                        max(maxLength, static_cast<int>(distance(i, j)));
                }
            }
        }
        return maxLength;
    }
    bool noRepet(string::iterator i, string::iterator j) {
        unordered_set<char> tmpSet;
        for (; i != j; i++) {
            auto re = tmpSet.insert(*i);
            if (!re.second) {
                return false;
            }
        }
        return true;
    }
};

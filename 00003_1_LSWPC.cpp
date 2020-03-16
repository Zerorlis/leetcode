#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "") return 0;
        int map
            [26];  // 一个用来存储当前滑动窗口滑动过程中字母最后一个字母位置的数组
        int maxLength = 1;
        for (int e = 1, b = 0; e <= s.size(); e++) {
            b = max(b, map[s[e] - 'a']);
            maxLength = max(maxLength, e - b);
            map[s[e] - 'a'] = e + 1;
        }
        return maxLength;
    }
};

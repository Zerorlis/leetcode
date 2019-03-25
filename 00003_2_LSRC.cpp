/** 使用移动窗口方法
 * 35.26%, 25.57%
 */
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> tempSet;
        int maxLength = 0;
        // [i,j),j是即将读取的下一个字母，tempSet包含了[i.j) 里面的所有字母
        for (auto i = s.begin(), j = s.begin(); j != s.end();) {
            auto result = tempSet.insert(*j);
            if (result.second) {
                // 插入成功，说明当前字母没有在之前的里面，于是i++
                j++;
                maxLength = max(maxLength, static_cast<int>(distance(i, j)));
            } else {
                tempSet.erase(*i);
                i++;
            }
        }
        return maxLength;
    }
};

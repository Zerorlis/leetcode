#include <cctype>
#include <string>
using namespace std;
class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() < 2) return true;
        bool res = true;
        // 如果第二个是大写字母
        if (isupper(word[1])) {
            for (auto p = word.begin(); p != word.end(); p++) {
                if (islower(*p)) res = false;
            }
        } else {
            for (auto p = (++word.begin()); p != word.end(); p++) {
                if (isupper(*p)) res = false;
            }
        }
        return res;
    }
};

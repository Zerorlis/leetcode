#include <cctype>
#include <string>
using namespace std;
class Solution {
public:
    int strongPasswordChecker(string s) {
        char isLower = 4;
        char isUpper = 2;
        char isDigit = 1;
        char format = 0;
        char llast = -1, last = -1;
        int threeChar = 0;  // 出现3个的次数,如果出现3个，使用一次替换就行
        for (auto p = s.begin(); p != s.end(); p++) {
            if (isupper(*p)) format |= isUpper;
            if (islower(*p)) format |= isLower;
            if (isdigit(*p)) format |= isDigit;
        }
    }
};

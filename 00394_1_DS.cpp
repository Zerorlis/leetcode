#include <cctype>
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        string res;
        stack<char> num;
        stack<char> alpha;
        for (auto p = s.begin(); p != s.end(); p++) {
            if (isalpha(*p)) {
                alpha.push(*p);
            }
            if (isdigit(*p)) {
                num.push(*p);
            }
            if (*p == '[') {
                num.push('[');
                alpha.push('[');
            }
            if (*p == ']') {
                // 这个时候要出栈了，直到下一个是[或者空为止,数字要先直接先出一个[,否则有问题
                num.pop();  // 把开头的[ 出去
                int repeat = 0;
                string tmpNum;
                while (!(num.empty() || num.top() == '[')) {
                    tmpNum = num.top() + tmpNum;
                    num.pop();
                }

                repeat = stoi(tmpNum);

                string tmpString;
                while (!(alpha.empty() || alpha.top() == '[')) {
                    tmpString = alpha.top() + tmpString;
                    alpha.pop();
                }

                // 字母要把现在的[去掉
                if (alpha.top() == '[') {
                    alpha.pop();
                }
                // 把重复的字母重新压回去
                for (; repeat != 0; repeat--) {
                    for (auto i = tmpString.begin(); i != tmpString.end();
                         i++) {
                        alpha.push(*i);
                    }
                }
            }
        }
        while (!alpha.empty()) {
            res = alpha.top() + res;
            alpha.pop();
        }
        return res;
    }
};

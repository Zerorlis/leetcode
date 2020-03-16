#include <string>
using namespace std;
class Solution {
public:
    string removeDuplicates(string S) {
        int top = -1;  // 栈顶,-1代表空
        for (int i = 0; i < S.size(); i++) {
            if (top == -1) {
                top++;
                S[top] = S[i];
                continue;  // 空的直接入栈
            }
            if (S[top] == S[i]) {
                top--;  // 一样的
                continue;
            } else {
                top++;  //不一样，入栈
                S[top] = S[i];
                continue;
            }
        }
        S.resize(top + 1);
        return S;
    }
};

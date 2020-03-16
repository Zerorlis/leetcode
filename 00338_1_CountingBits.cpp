#include <vector>
using namespace std;
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num + 1);
        for (int i = 1; i <= num; i++) {
            if (i % 2 == 0) {
                // 偶数
                ans[i] = ans[i / 2];
            } else {
                // 奇数
                ans[i] = ans[i - 1] + 1;
            }
        }
        return ans;
    }
};

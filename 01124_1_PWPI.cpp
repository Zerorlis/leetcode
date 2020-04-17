#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        // 使用的单调栈
        // 先求前缀和，pre[i]代表[0,i)之间的元素的和
        for_each(hours.begin(), hours.end(),
                 [](int& j) { j = (j > 8 ? 1 : -1); });
        vector<int> pre(hours.size() + 1);
        pre[0] = 0;
        for (int i = 0; i < (int)hours.size(); i++) {
            pre[i + 1] = pre[i] + hours[i];
        }
        // 如果前缀和最后一个元素大于0，说明整个数组都满足要求
        if (pre.back() >= 1) return hours.size();
        // 构建栈，栈中元素递减
        // [i,j)为满足要求的数据，pre[i,j)
        // stk中存的是i,j从右边开始扫描
        stack<int> stk;
        for (int i = 0; i < (int)pre.size(); i++) {
            if (stk.empty() || pre[stk.top()] > pre[i]) stk.push(i);
        }
        int ans = 0;

        for (int j = pre.size() - 1; j >= ans; j--) {
            while (!stk.empty() && pre[stk.top()] < pre[j]) {
                ans = max(ans, j - stk.top());
                stk.pop();
            }
        }
        return ans;
    }
};

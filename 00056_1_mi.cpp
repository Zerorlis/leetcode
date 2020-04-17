#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.empty()) return res;
        // 先排序，根据第一个元素从小到大排序
        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });
        // 排序完成，开始merge
        res.push_back(intervals[0]);
        for (auto p = ++intervals.begin(); p != intervals.end(); p++) {
            auto& before = res.back();
            // 后面的尾巴在前面的尾巴之前
            if ((*p)[1] <= before[1]) {
                continue;
            } else if ((*p)[0] > before[1]) {
                // 后面的头在前面的尾巴之后
                res.push_back(*p);
            } else if ((*p)[0] <= before[1]) {
                // 后面的头在前面的尾巴之前
                before[1] = (*p)[1];
            }
        }
        return res;
    }
};

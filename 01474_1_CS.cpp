#include <vector>
using namespace std;
/* 使用动态规划，用一个数值，表示[0,i]中包括i的最大值，当要处理i+1的时候，比较i+1和num+i+1的值*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums.front();  // 返回的结果
        int max_i = 0;           // 前一个结果中最大的,包括i-1的值
        for (auto i : nums) {
            max_i = max(max_i + i, i);
            res = max(res, max_i);
        }
        return res;
    }
};

/**
 * @file 00128_1_LCS.cpp
 * @brief 使用的是hash表，简直了,,20.50%,0.2%
 * @author Zerorlis
 * @version 0.1
 * @date 2019-03-29
 */
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<long> map(nums.begin(), nums.end());
        int max = 0;
        while (!map.empty()) {
            // 打算便利搜索一下，因为hashmap的插入删除都是o(1)的，所以并不会有太多的搜索
            int tmpMax = 0;
            // 搜索自己和前面的部分,注意溢出
            long tmpInt = *map.begin();
            long tmpInt1 = tmpInt;
            while (map.erase(tmpInt1--)) {
                ++tmpMax;
            }
            // 搜索后面的部分 注意溢出
            long tmpInt2 = tmpInt + 1;
            while (map.erase(tmpInt2++)) {
                ++tmpMax;
            }
            max = (tmpMax > max ? tmpMax : max);
        }
        return max;
    }
};

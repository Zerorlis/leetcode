/**
 * @file 00169_1_MajorityElement.cpp
 * @brief 摩尔投票法
 * @author Zerorlis
 * @version 0.1
 * @date 2019-05-23
 */
#include <vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = nums[0];
        int time = 1;
        auto p = ++nums.begin();
        while (p != nums.end()) {
            if (*p == res) {
                time++;
            } else {
                time--;
            }
            if (time == 0) {
                res = *++p;  // 选下一个数字
                time = 1;
            }
            ++p;
        }
        return res;
    }
};

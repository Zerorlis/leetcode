/**
 * @file 00169_1_MajorityElement.cpp
 * @brief 失败，这个算法并不好，极端情况无法解决
 * @author Zerorlis
 * @version 0.1
 * @date 2019-05-23
 */
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int trytime = 11;
        if (nums.size() <= trytime) return findmore(nums);
        vector<int> temp;
        srand((unsigned)time(NULL));  // 随机种子
        for (int j = 0; j < trytime; j++) {
            temp.push_back(nums[rand() % nums.size()]);
        }
        return findmore(temp);
    }
    int findmore(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int max = 0;            //最大出现次数
        int cur = 1;            //当前出现次数
        int max_num = nums[0];  //出现次数最多的数字

        //开始遍历查找出现次数最多的数字
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                cur++;
            } else {
                if (cur > max) {
                    max = cur;
                    max_num = nums[i];
                }
                cur = 1;
            }
        }
        return max_num;
    }
};

/**
 * @file 00746_1_MinCostClimbingStairs.cpp
 * @brief 打算用动态规划来做,典型的动态规划问题
 * @author Zerorlis
 * @version 0.1
 * @date 2019-05-05
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> res(cost.size(), 0);
        res[0] = cost[0];
        res[1] = cost[1];
        for (int i = 2; i < res.size(); i++) {
            res[i] = min(res[i - 1] + cost[i], res[i - 2] + cost[i]);
        }
        return min(*--res.end(), *----res.end());
    }
};

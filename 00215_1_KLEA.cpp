/**
 * @file 00215_1_KLEA.cpp
 * @brief 使用暴力方法，直接用set排好序,35.26%,5.15%
 * @author Zerorlis
 * @version 0.1
 * @date 2019-03-26
 */
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> t(nums.begin(), nums.end());
        auto p = t.end();
        for (int i = 0; i < k; i++) {
            p--;
        }
        return *p;
    }
};

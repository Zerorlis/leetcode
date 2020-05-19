#include <vector>
using namespace std;
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<int> tmp(nums.size());
        return mergeSort(nums, 0, nums.size() - 1, tmp);
    }
    // 一个归并排序的函数，同时返回这一小段的逆序对数量
    // 从小到大排序
    int mergeSort(vector<int>& nums, int left, int right, vector<int>& tmp) {
        if (left >= right) return 0;
        int mid = (left + right) / 2;
        // 先分治,左右两段都排序好
        // tmp是排序后的数组
        int res = 0;
        res += mergeSort(nums, left, mid, tmp);
        res += mergeSort(nums, mid + 1, right, tmp);
        // 左右数组排序完成
        int leftPoint = left;
        int rightPoint = mid + 1;
        for (int i = left; i <= right; i++) {
            if (leftPoint > mid) {
                // 只剩下右边
                tmp[i] = nums[rightPoint];
                rightPoint++;
                continue;
            }
            if (rightPoint > right) {
                // 只剩下左边
                tmp[i] = nums[leftPoint];
                leftPoint++;
                continue;
            }
            // 左右都有
            if (nums[leftPoint] <= nums[rightPoint]) {
                // 不构成逆序，不用加结果
                tmp[i] = nums[leftPoint];
                leftPoint++;
            } else {
                tmp[i] = nums[rightPoint];
                res += (mid - leftPoint + 1);
                rightPoint++;
            }
        }
        // 合并完成，把tmp复制到nums中
        copy(tmp.begin() + left, tmp.begin() + right + 1, nums.begin() + left);
        return res;
    }
};

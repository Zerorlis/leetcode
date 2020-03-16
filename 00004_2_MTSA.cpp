// 思路是利用二分法
// 此方法的时间复杂度是log(min(m,n))
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 保证nums1是数字个数比较小的数组
        if (nums1.size() > nums2.size()) swap(nums1, nums2);
        int m = nums1.size();
        int n = nums2.size();
        if (m == 1 && n == 1) return (nums1[0] + nums2[0]) / 2.0;
        // 如果有一个数组是空的
        if (m == 0)
            return n % 2 == 0 ? (nums2[n / 2] + nums2[n / 2 - 1]) / 2.0
                              : nums2[n / 2];
        // 如果有个数组只有1个数，比较难办，所以处理下
        if (m == 1) {
            if (n % 2 == 1) {
                // 在中间数的左边
                if (nums2[n / 2] > nums1[0])
                    return (nums2[n / 2] + max(nums2[n / 2 - 1], nums1[0])) /
                           2.0;
                else if (nums2[n / 2] < nums1[0])
                    return (nums2[n / 2] + min(nums2[n / 2 + 1], nums1[0])) /
                           2.0;
                else
                    return nums1[0];
            } else {
                if (nums1[0] <= nums2[n / 2 - 1])
                    return nums2[n / 2 - 1];
                else if (nums1[0] >= nums2[n / 2])
                    return nums2[n / 2];
                else
                    return nums1[0];
            }
        }
        // k不能取到最后的一个数，也就是m-1，也不能取到k=-1
        int low = 0;
        int hight = m - 1;
        int k = (m - 1) / 2;  // 二分法,初始情况直接从第一个数组的一半开始
        while (!(nums2[(m + n) / 2 - k - 2] <= nums1[k + 1] &&
                 nums1[k] <= nums2[(m + n) / 2 - k - 1])) {
            if (nums2[(m + n) / 2 - k - 2] > nums1[k + 1]) {
                low = k + 1;
            }
            if (nums1[k] > nums2[(m + n) / 2 - k - 1]) {
                hight = k - 1;
            }
            k = (low + hight) / 2;
            if (hight < 0) {
                if (m == n) return (nums2.back() + nums1.front()) / 2.0;
                return (m + n) % 2 == 0
                           ? (min(nums2[(m + n) / 2], nums1.front()) +
                              nums2[(m + n) / 2 - 1]) /
                                 2.0
                           : min(nums2[(m + n) / 2], nums1.front());
            }
            if (k == m - 1) {
                if (m == n) return (nums1.back() + nums2.front()) / 2.0;
                return (m + n) % 2 == 0
                           ? (max(nums2[(m + n) / 2 - m - 1], nums1.back()) +
                              nums2[(m + n) / 2 - m]) /
                                 2.0
                           : max(nums2[(m + n) / 2 - m], nums1.back());
            }
        }
        if ((m + n) % 2 == 0)
            return (max(nums1[k], nums2[(m + n) / 2 - k - 2]) +
                    min(nums1[k + 1], nums2[(m + n) / 2 - k - 1])) /
                   2.0;
        else
            return min(nums1[k + 1], nums2[(m + n) / 2 - k - 1]);
    }
};

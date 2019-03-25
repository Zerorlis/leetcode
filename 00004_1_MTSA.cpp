/**
 * 思路是当做一个链表处理找中位数
 * 97.24%,73.60%
 *
 *
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto l1 = nums1.begin();
        auto l2 = nums2.begin();
        auto e1 = nums1.end();
        auto e2 = nums2.end();
        // 接下来左右各自移动多少个单位，移动size和/2个单位，分别得到左边和右边的数字
        auto count = nums1.size() + nums2.size();
        for (int i = 0; i < (count - 1) / 2; i++) {
            getNextMinNumber(l1, l2, e1, e2);
        }
        // 此时已经到中位数边上了,如果和是奇数，那么接下来较小的那个数就是中位数,
        // 如果是偶数，那么接下来的两个比较小的数是中位数

        if (count % 2 == 1) {
            return static_cast<double>(getNextMinNumber(l1, l2, e1, e2));
        } else {
            int num1 = getNextMinNumber(l1, l2, e1, e2);
            int num2 = getNextMinNumber(l1, l2, e1, e2);
            return (static_cast<double>(num1 + num2)) / 2;
        }
    }
    int getNextMinNumber(vector<int>::iterator& l1, vector<int>::iterator& l2,
                         vector<int>::iterator& end1,
                         vector<int>::iterator& end2) {
        int num1 = (l1 == end1) ? INT_MAX : *l1;
        int num2 = (l2 == end2) ? INT_MAX : *l2;
        if (num1 <= num2) {
            return *(l1++);
        } else {
            return *(l2++);
        }
    }
};

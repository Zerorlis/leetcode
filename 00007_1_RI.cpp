/**
 * @file 00007_1_RI.cpp
 * @brief 整数反转，用数学方法得到最后一位，当做栈，为了防止溢出，决定使用long
 * @author Zerorlis
 * @version 0.1
 * @date 2019-04-09
 */

#include <climits>
#include <iostream>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        long xx = (long)x;
        long res = 0;
        while (xx != 0) {
            long pop = xx % 10;
            xx /= 10;  // 出栈
            res = res * 10 + pop;
        }
        if (res > INT_MAX || res < INT_MIN)
            return 0;
        else
            return (int)res;
    }
};

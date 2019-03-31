/**
 * @file 00365_1_WJP.cpp
 * @brief
 * 水壶问题，可以转化为球z是不是x和y的最大公约数的倍数，最大公约数可以用辗转相除法和辗转相减法
 * @author Zerorlis
 * @version 0.1
 * @date 2019-03-26
 */

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (z == 0) {
            return true;
        } else if (x + y < z) {
            return false;
        } else if (x == 0 && y == z) {
            return true;
        } else if (y == 0 && x == z) {
            return true;
        } else if (x + y >= z && x != 0 && y != 0) {
            return z % getGcdBydivision(x, y) == 0;
        } else {
            return false;
        }
    }
    // 获取最大公约数
    int getGcdBydivision(int x, int y) {
        int r;
        while (y != 0) {
            r = x % y;
            x = y;
            y = r;
        }
        return x;
    }
};

/**
 * @file 00273_1_IEW.cpp
 * @brief 把数字转化成对应的英文字符
 * @author Zerorlis
 * @version 0.1
 * @date 2019-04-14
 */
#include <sstream>
#include <string>
using namespace std;
class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        int a = num % 1000;               // 1000 以下
        int b = num / 1000 % 1000;        // thousand
        int c = num / 1000000 % 1000;     // million
        int d = num / 1000000000 % 1000;  // billion
        ostringstream res;
        if (d != 0) {
            res << numberDownThousand(d) << " "
                << "Billion";
        }
        if (c != 0) {
            res << numberDownThousand(c) << " "
                << "Million";
        }
        if (b != 0) {
            res << numberDownThousand(b) << " "
                << "Thousand";
        }
        if (a != 0) {
            res << numberDownThousand(a);
        }
        return res.str().substr(1);
    }

    // 只负责1-999
    string numberDownThousand(int num) {
        int a = num % 10;        // 个位
        int b = num / 10 % 10;   // 十位
        int c = num / 100 % 10;  // 百位
        string singles[10] = {"Zero", "One", "Two",   "Three", "Four",
                              "Five", "Six", "Seven", "Eight", "Nine"};
        string tenToTwenty[10] = {"Ten",      "Eleven",  "Twelve",  "Thirteen",
                                  "Fourteen", "Fifteen", "Sixteen", "Seventeen",
                                  "Eighteen", "Nineteen"};
        string tens[10] = {"Zero",  "Ten",   "Twenty",  "Thirty", "Forty",
                           "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        ostringstream res;
        if (c != 0)
            res << " " << singles[c] << " "
                << "Hundred";
        if (b == 0) {
            // 十位是0的时候什么都不做
        } else if (b == 1) {
            res << " " << tenToTwenty[a];
        } else {
            res << " " << tens[b];
        }
        if (a == 0) {
            //个位是0的时候什么都不做
        } else if (b != 1) {  // 十几的时候没有输出
            res << " " << singles[a];
        }
        return res.str();  //注意，返回值前面带一个空格
    }
};

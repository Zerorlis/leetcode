/**
 * @file 00467_1_USWS.cpp
 * @brief 思路，用尾字母和长度标记子字符串，如abcd res[d]=4,代表着abcd bcdcd
 * d这几个子字符串，注意，abc这样的字符串由c来标注
 * @author Zerorlis
 * @version 0.1
 * @date 2019-05-23
 */
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> record(26, 0);  // 用char - 'a'来代表位置
        int l = 1;
        // 首字母特殊处理
        record[p[0] - 'a'] = 1;
        for (int i = 1; i < p.size(); i++) {
            if (p[i] - p[i - 1] == 1 || (p[i] == 'a' && p[i - 1] == 'z')) {
                l += 1;
            } else {
                l = 1;
            }
            record[p[i] - 'a'] = max(l, record[p[i] - 'a']);
        }
        return accumulate(record.begin(), record.end(), 0);
    }
};

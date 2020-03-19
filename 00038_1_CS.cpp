
#include <string>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for (int i = 1; i < n; i++) {
            char tmp = res[0];
            int count = 0;
            string tmpStr = "";
            for (auto p = res.begin(); p != res.end(); p++) {
                if (*p == tmp) {
                    count++;
                } else {
                    tmpStr.push_back(count + '0');
                    tmpStr.push_back(tmp);
                    count = 1;
                    tmp = *p;
                }
            }
            if (count != 0) {
                tmpStr.push_back(count + '0');
                tmpStr.push_back(tmp);
            }
            res = move(tmpStr);
        }
        return res;
    }
};

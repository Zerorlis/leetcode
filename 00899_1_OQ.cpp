#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    string orderlyQueue(string S, int K) {
        if (K > 1) {
            sort(S.begin(), S.end());
            return S;
        }
        string res = S;
        for (int i = 0; i < (int)S.size(); i++) {
            string tmpS = S.substr(i) + S.substr(0, i);
            res = min(move(tmpS), res);
        }
        return res;
    }
};

#include <vector>
using namespace std;
class Solution {
public:
    vector<int> fraction(vector<int>& cont) {
        vector<int> res(2);
        res[1] = 1;
        res[0] = cont.back();
        for (int i = cont.size() - 2; i >= 0; i--) {
            int tmp = res[0];
            res[0] = cont[i] * tmp + res[1];
            res[1] = tmp;
        }
        return res;
    }
};

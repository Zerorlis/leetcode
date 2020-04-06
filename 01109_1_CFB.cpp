#include <vector>
using namespace std;
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n + 1);
        for (auto& booking : bookings) {
            res[booking[0] - 1] += booking[2];
            res[booking[1]] -= booking[2];
        }
        res.pop_back();  // 删除尾巴上的数字
        for (int i = 1; i < (int)res.size(); i++) {
            res[i] += res[i - 1];
        }
        return res;
    }
};

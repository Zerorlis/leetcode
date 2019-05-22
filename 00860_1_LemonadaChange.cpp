#include <vector>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int moneys[2] = {};
        for (int m : bills) {
            if (m == 5) {
                moneys[0]++;
                continue;
            } else if (m == 10) {
                if (moneys[0] == 0) {
                    return false;
                } else {
                    moneys[0]--;
                    moneys[1]++;
                    continue;
                }
            } else {
                if (moneys[1] >= 1 && moneys[0] >= 1) {
                    moneys[0]--;
                    moneys[1]--;
                    continue;
                } else if (moneys[0] >= 3) {
                    moneys[0] -= 3;
                    continue;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

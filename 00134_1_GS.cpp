#include <vector>
using namespace std;
class Solution {
public:
    // 思路，首先假设这个车子一开始有无限汽油，那么总油量会不断上下变化
    // 然后，从油耗的最低点出发，一定能走完全程。
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int finalGas = 0;
        int minGas = 0;
        int res = 0;
        for (int i = 0; i < (int)gas.size(); i++) {
            finalGas += gas[i] - cost[i];
            if (finalGas < minGas) {
                minGas = finalGas;
                res = i + 1;
            }
        }
        if (finalGas < 0) return -1;
        if (res == gas.size()) return 0;
        return res;
    }
};

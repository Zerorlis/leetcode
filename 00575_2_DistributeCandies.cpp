#include <algorithm>
#include <bitset>
#include <vector>
using namespace std;
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        bitset<200001> bs;
        int typeNum = 0;
        for (auto candy : candies) {
            if (!bs.test(candy + 100000)) {
                bs.set(candy + 100000);
                ++typeNum;
            }
        }
        return min(typeNum, (int)candies.size() / 2);
    }
};

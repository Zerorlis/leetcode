#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        sort(candies.begin(), candies.end());
        int typeNum = unique(candies.begin(), candies.end()) - candies.begin();
        return min(typeNum, (int)candies.size() / 2);
    }
};

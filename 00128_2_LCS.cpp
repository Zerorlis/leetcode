#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> map;
        map.reserve(nums.size() * 2);
        for (auto i : nums) {
            map.emplace(i, 0);
        }
        int result = 0;
        for (auto i : nums) {
            result = max(result, getNum(map, i));
        }
        return result;
    }
    int getNum(unordered_map<int, int>& map, int j) {
        auto p = map.find(j);
        if (p == map.end()) {
            return 0;
        }
        // 能够在map中找到这个数,如果是0的画，说明至少还没有被查询过
        if (p->second == 0) p->second = 1 + getNum(map, j - 1);
        return p->second;
    }
};

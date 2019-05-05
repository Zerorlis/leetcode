#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        set.reserve(nums.size());
        for (auto num : nums) {
            auto a = set.insert(num);
            if (!a.second) {
                return true;
            }
        }
        return false;
    }
};

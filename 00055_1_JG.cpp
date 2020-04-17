#include <vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jumpLoc = 0;
        int lastLoc = nums.size() - 1;
        for (int i = 0; i <= lastLoc; i++) {
            if (i <= jumpLoc) {
                jumpLoc = max(jumpLoc, nums[i] + i);
                if (jumpLoc >= lastLoc) return true;
            } else {
                return false;
            }
        }
        return false;
    }
};

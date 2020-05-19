#include <vector>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int maxPosition = 0;
        int res = 0;
        int end = 0;
        for (int i = 0; i < nums.size(); i++) {
            maxPosition = max(maxPosition, i + nums[i]);
            if (maxPosition >= nums.size() - 1) {
                res++;
                break;
            }
            if (i == end) {
                end = maxPosition;
                res++;
            }
        }
        return res;
    }
};

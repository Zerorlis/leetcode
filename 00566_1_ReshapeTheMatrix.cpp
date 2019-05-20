#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (nums.size() == 0) return nums;
        if (nums.size() * nums[0].size() != r * c) return nums;
        int ro = nums.size();
        int co = nums[0].size();
        vector<vector<int>> res(r, vector<int>(c, 0));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                res[i][j] = nums[(i * c + j) / co][(i * c + j) % co];
            }
        }
    }
};

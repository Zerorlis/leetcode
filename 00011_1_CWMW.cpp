#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int mostWater = 0;
        while (i < j) {
            mostWater = max(mostWater, min(height[i], height[j]) * (j - i));
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return mostWater;
    }
};

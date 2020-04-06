#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int max_light = 0;
        int res = 0;
        // i代表是第几个灯泡，访问的时候用i-1
        for (int i = 0; i < light.size(); i++) {
            max_light = max(max_light, light[i]);
            if (max_light == i + 1) res++;
        }
        return res;
    }
};

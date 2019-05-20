#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> beautifulArray(int N) {
        if (N == 1) return {1};
        if (N == 2) return {1, 2};
        if (N == 3) return {1, 3, 2};
        if (N == 4) return {1, 3, 2, 4};
        // 生成一个漂亮数组，数字个数大于N
        vector<int> temp = {1, 3, 2, 4};
        while (temp.size() < N) {
            for (auto& i : temp) {
                i = i * 2 - 1;
            }
            int s = temp.size();
            for (int i = 0; i < s; i++) {
                temp.push_back(temp[i] + 1);
            }
        }
        vector<int> res;
        copy_if(temp.begin(), temp.end(), back_inserter(res),
                [=](int i) { return i <= N; });
        return res;
    }
};

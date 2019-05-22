#include <algorithm>
#include <functional>
#include <iterator>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> counters;
        for (auto a : nums) {
            counters[a]++;
        }
        vector<pair<int, int>> res(k);  // 存放结果，至少有k个元素的位置
        partial_sort_copy(counters.begin(), counters.end(), res.begin(),
                          res.end(), [](pair<int, int>& a, pair<int, int>& b) {
                              return a.second > b.second;
                          });
        vector<int> result;
        for (auto a : res) {
            result.push_back(a.first);
        }
        return result;
    }
};

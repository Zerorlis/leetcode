#include <set>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        set<int> res;
        for (auto p = nums.begin(); p != nums.end(); p++) {
            auto tmp = res.find(*p);
            if (tmp != res.end()) {
                res.erase(tmp);
            } else {
                res.insert(*p);
            }
        }
        vector<int> resList;
        for (auto p = res.begin(); p != res.end(); p++) {
            resList.push_back(*p);
        }
        return resList;
    }
};

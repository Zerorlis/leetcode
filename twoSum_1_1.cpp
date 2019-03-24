/**
 * 使用了hash表的
 */
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> re;
        unordered_multimap<int, int> tempMap;
        for(int i=0;i<nums.size();i++){
            tempMap.insert(unordered_multimap<int,int>::value_type(nums[i],i));
        }
        for(int i=0;i<nums.size();i++){
            // 尝试寻找另一半的差所在的位置
            auto j = tempMap.find(target-nums[i]);
            if(j!=tempMap.end()){
                // 如果找到了就检查是不是下标一样
                if(j->second !=i){
                    // 下标不等于自己本身
                    re.push_back(j->second);
                    re.push_back(i);
                    break;
                }
            }
        }
        return re;
    }
};

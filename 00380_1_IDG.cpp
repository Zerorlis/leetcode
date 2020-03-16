#include <random>
#include <unordered_map>
#include <vector>
using namespace std;
class RandomizedSet {
public:
    vector<int> list;
    unordered_map<int, int> map;
    default_random_engine e;
    /** Initialize your data structure here. */
    RandomizedSet() {}

    /** Inserts a value to the set. Returns true if the set did not already
     * contain the specified element. */
    bool insert(int val) {
        if (map.count(val)) return false;
        list.push_back(val);
        map.insert(make_pair(val, list.size() - 1));
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the
     * specified element. */
    bool remove(int val) {
        auto remove_val = map.find(val);

        if (remove_val == map.end()) return false;
        // 最后面的元素移动到前面去
        map[list.back()] = remove_val->second;
        list[remove_val->second] = list.back();
        map.erase(remove_val);
        list.pop_back();

        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        uniform_int_distribution<int> u(0, list.size() - 1);
        return list[u(e)];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

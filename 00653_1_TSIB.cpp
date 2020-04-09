#include <unordered_set>
#include "tree.h"
using namespace std;
class Solution {
public:
    unordered_set<int> set;
    bool findTarget(TreeNode* root, int k) { return find(root, k); }
    bool find(TreeNode* node, int k) {
        if (!node) return false;
        if (set.find(k - node->val) != set.end()) return true;
        set.insert(node->val);
        return find(node->left, k) || find(node->right, k);
    }
};

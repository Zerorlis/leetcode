#include <algorithm>
#include <cstdlib>
#include <utility>
#include "tree.h"
using namespace std;
class Solution {
public:
    bool isBalanced(TreeNode* root) { return balancedHelper(root).second; }
    pair<int, bool> balancedHelper(TreeNode* node) {
        // pair返回值分别是高度和是否平衡
        // 如果是叶子节点，返回
        if (!node) return make_pair(0, true);
        auto left_res = balancedHelper(node->left);
        if (!left_res.second) return make_pair(-1, false);
        auto right_res = balancedHelper(node->right);
        if (!right_res.second) return make_pair(-1, false);
        if (abs(left_res.first - right_res.first) > 1)
            return make_pair(-1, false);
        return make_pair(max(left_res.first, right_res.first) + 1, true);
    }
};

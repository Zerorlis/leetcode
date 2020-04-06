#include <algorithm>
#include <vector>
#include "tree.h"
using namespace std;
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructSonBinaryTree(nums.begin(), nums.end());
    }
    TreeNode* constructSonBinaryTree(const vector<int>::iterator& left,
                                     const vector<int>::iterator& right) {
        if (left == right) return NULL;
        // find root
        auto root_p = max_element(left, right);
        auto root = new TreeNode(*root_p);
        root->left = constructSonBinaryTree(left, root_p);
        root->right = constructSonBinaryTree(++root_p, right);
        return root;
    }
};

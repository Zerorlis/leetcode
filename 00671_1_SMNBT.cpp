#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;
class Solution {
public:
    int findSecondMinimumValue(TreeNode *root) {
        int a;
        if ((a = findSecondMinimumValueX(root)) == INT_MAX) {
            return -1;
        } else {
            return a;
        }
    }
    int findSecondMinimumValueX(TreeNode *root) {
        // 这个节点是一个叶子节点
        if (root->left == nullptr) {
            return INT_MAX;
        }
        int res = INT_MAX;
        if (root->left->val != root->val) {
            res = min(res, root->left->val);
        } else {
            res = min(res, findSecondMinimumValueX(root->left));
        }
        if (root->right->val != root->val) {
            res = min(res, root->right->val);
        } else {
            res = min(res, findSecondMinimumValueX(root->right));
        }
        return res;
    }
};

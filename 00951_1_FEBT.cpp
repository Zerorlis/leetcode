/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL) return true;  // 两个都是空
        if (!(root1 && root2)) return false;  // 有一个是空,两个都是空上面判断过
        if (root1->val != root2->val) return false;  // 根要相等
        return (flipEquiv(root1->left, root2->left) &&
                flipEquiv(root1->right, root2->right)) ||
               (flipEquiv(root1->left, root2->right) &&
                flipEquiv(root1->right, root2->left));
    }
};

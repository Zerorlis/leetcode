
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSubtree(TreeNode *s, TreeNode *t) {
        if (s == nullptr) return false;
        if (isSameTree(s, t)) return true;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    bool isSameTree(TreeNode *s, TreeNode *t) {
        if (s == t) return true;
        if (s == nullptr || t == nullptr) return false;
        return s->val == t->val && isSameTree(s->left, t->left) &&
               isSameTree(s->right, t->right);
    }
};

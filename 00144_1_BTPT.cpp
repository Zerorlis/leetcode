#include <stack>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode *> stk;
        vector<int> res;
        if (!root) return res;
        stk.push(root);
        while (!stk.empty()) {
            auto p = stk.top();
            res.push_back(p->val);
            stk.pop();
            // 先压入右树
            if (p->right != NULL) stk.push(p->right);
            if (p->left != NULL) stk.push(p->left);
        }
        return res;
    }
};

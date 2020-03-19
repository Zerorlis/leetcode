#include <vector>
using namespace std;
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for (int i = 1; i <= 9; i++) {
            if (i > n) return res;
            res.push_back(i);
            dfs(res, i, n);
        }
        return res;
    }
    void dfs(vector<int>& res, int k, int n) {
        for (int i = 0; i <= 9; i++) {
            int tmp = k * 10 + i;
            if (tmp > n) return;
            res.push_back(tmp);
            dfs(res, tmp, n);
        }
    }
};

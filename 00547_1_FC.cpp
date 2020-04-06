#include <vector>
using namespace std;
class Solution {
public:
    // 深度优先访问第i个人的所有朋友
    void dfs(vector<vector<int>>& M, vector<bool>& visited, int i) {
        for (int j = 0; j < (int)M.size(); j++) {
            if (!visited[j] && M[i][j]) {
                visited[j] = true;
                dfs(M, visited, j);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        int res = 0;
        vector<bool> visited(M.size());  // 已经访问过的节点
        for (int i = 0; i < (int)M.size(); i++) {
            if (visited[i]) continue;  // 已经访问过
            visited[i] = true;         //标记此人访问过
            dfs(M, visited, i);
            res++;  // 做完一次深度优点，那么朋友圈数量加1
        }
        return res;
    }
};

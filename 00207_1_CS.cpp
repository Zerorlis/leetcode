#include <vector>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses);
        // 图换个表示法，用邻接表
        vector<vector<int>> map(numCourses);
        for (vector<int>& prerequisity : prerequisites) {
            map[prerequisity[0]].push_back(prerequisity[1]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (dfs(map, i, visited)) return false;  // 有环
        }
        return true;
    }
    // i代表访问第i个节点,返回值是这次dfs是否发现有环
    bool dfs(vector<vector<int>>& map, int i, vector<int>& visited) {
        if (visited[i] == -1) return false;  //已经访问过，没有环
        if (visited[i] == 1) return true;    // 被本轮访问过，有环
        visited[i] = 1;                      // 本轮访问开始
        for (int node : map[i]) {
            if (dfs(map, node, visited))
                return true;  //深度优先，发现有环，就返回true;
        }
        visited[i] = -1;  //此节点深度优先完成，没有环
        return false;
    }
};

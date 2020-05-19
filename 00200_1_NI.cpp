#include <vector>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (int i = 0; i < (int)grid.size(); i++) {
            for (int j = 0; j < (int)grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }
    vector<vector<int>> deviation = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        for (int t = 0; t < 4; t++) {
            int xx = i + deviation[t][0];
            int yy = j + deviation[t][1];
            if (xx >= 0 && yy >= 0 && xx < m && yy < n && grid[xx][yy] == '1') {
                grid[xx][yy] = '2';
                dfs(grid, xx, yy);
            }
        }
    }
};

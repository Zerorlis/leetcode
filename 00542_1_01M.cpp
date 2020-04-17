#include <queue>
#include <tuple>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int deviation[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int m = matrix.size();
        int n = matrix[0].size();
        queue<pair<int, int>>
            list;  //广度优先，下次要访问的对象是这个队列中对象的边缘
        vector<vector<bool>> visited(
            m, vector<bool>(n, false));  // 已经参观过的位置
        vector<vector<int>> res(m, vector<int>(n, 0));  // 结果
        // 所有的0进入初始队列
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    list.emplace(i, j);  // 这样插入比较快
                    visited[i][j] = true;
                }
            }
        }
        while (!list.empty()) {
            int x, y;
            tie(x, y) = list.front();
            // 边上4个点
            for (int i = 0; i < 4; i++) {
                int xx = x + deviation[i][0];
                int yy = y + deviation[i][1];
                if (xx >= 0 && yy >= 0 && xx < m && yy < n &&
                    visited[xx][yy] == false) {
                    res[xx][yy] = res[x][y] + 1;
                    visited[xx][yy] = true;
                    list.emplace(xx, yy);
                }
            }
            list.pop();
        }
        return res;
    }
};

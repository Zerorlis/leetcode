#include <vector>
using namespace std;
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size();
        int column = grid[0].size();
        int res = 0;
        for (int i = 1; i < row - 1; i++) {
            for (int j = 1; j < column - 1; j++) {
                if (grid[i][j] == 5) {
                    switch (grid[i - 1][j - 1]) {
                        case 8:
                        case 6:
                        case 4:
                        case 2:
                            res += grid[i - 1][j - 1] * grid[i - 1][j] *
                                                   grid[i - 1][j + 1] *
                                                   grid[i][j - 1] * grid[i][j] *
                                                   grid[i][j + 1] *
                                                   grid[i + 1][j - 1] *
                                                   grid[i + 1][j] *
                                                   grid[i + 1][j + 1] ==
                                               362880 &&
                                           grid[i - 1][j - 1] + grid[i - 1][j] +
                                                   grid[i - 1][j + 1] ==
                                               15 &&
                                           grid[i][j - 1] + grid[i][j] +
                                                   grid[i][j + 1] ==
                                               15 &&
                                           grid[i + 1][j - 1] + grid[i + 1][j] +
                                                   grid[i + 1][j + 1] ==
                                               15 &&
                                           grid[i - 1][j - 1] + grid[i][j - 1] +
                                                   grid[i + 1][j - 1] ==
                                               15 &&
                                           grid[i - 1][j] + grid[i][j] +
                                                   grid[i + 1][j] ==
                                               15 &&
                                           grid[i - 1][j + 1] + grid[i][j + 1] +
                                                   grid[i + 1][j + 1] ==
                                               15 &&
                                           grid[i - 1][j - 1] + grid[i][j] +
                                                   grid[i + 1][j + 1] ==
                                               15 &&
                                           grid[i - 1][j + 1] + grid[i][j] +
                                                   grid[i + 1][j - 1] ==
                                               15
                                       ? 1
                                       : 0;
                            break;
                    }
                }
            }
        }
        return res;
    }
};


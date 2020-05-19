#include <vector>
using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        // 动态规划，转移方程为min(dp(i-1,j),dp(i-1,j-1),dp(i,j-1)+1);
        int row = matrix.size();
        int col = matrix[0].size();
        int res = 0;
        vector<vector<int>> dp(row + 1, vector<int>(col + 1));
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                if (matrix[i - 1][j - 1] == '0') {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] =
                        min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) +
                        1;
                    res = max(dp[i][j], res);
                }
            }
        }
        return res * res;
    }
};

#include <vector>
using namespace std;
class Solution {
public:
    static constexpr int mod = 1000000007;
    static constexpr int coin[4] = {1, 5, 10, 25};
    int waysToChange(int n) {
        vector<vector<int>> dp(4, vector<int>(n + 1, 0));
        for (int i = 0; i < n + 1; i++) {
            dp[0][i] = 1;
        }
        for (int i = 1; i < 4; i++) {
            for (int j = 0; j < n + 1; j++) {
                if (j - coin[i] >= 0) {
                    dp[i][j] = (dp[i - 1][j] + dp[i][j - coin[i]]) % mod;
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[3][n];
    }
};

#include <climits>
#include <vector>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    setZero(matrix, i, j);
                }
            }
        }
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == INT_MAX) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    void setZero(vector<vector<int>>& matrix, int i, int j) {
        for (int m = 0; m < matrix[0].size(); m++) {
            if (matrix[i][m] != 0) {
                matrix[i][m] = INT_MAX;
            }
        }
        for (int n = 0; n < matrix.size(); n++) {
            if (matrix[n][j] != 0) {
                matrix[n][j] = INT_MAX;
            }
        }
    }
};

#include <array>
#include <bitset>
#include <tuple>
#include <vector>
using namespace std;
class Solution {
public:
    array<bitset<9>, 9> col;  // 列, 代表这个未知已经填写
    array<bitset<9>, 9> row;  // 行
    array<bitset<9>, 9> box;  // 9个圈圈
    vector<tuple<int, int>> space;  // 当前空着的格子，方便寻找下一个位置
    void solveSudoku(vector<vector<char>>& board) {
        // 初始化
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    // space.push_back(make_tuple(i,j)); // 这个产生临时变量了
                    space.emplace_back(i, j);  // 不产生临时变量
                } else {
                    int num = board[i][j] - '1';
                    row[i].set(num);
                    col[j].set(num);
                    box[(i / 3) * 3 + j / 3].set(num);
                }
            }
        }
        dfs(0, board);
    }
    bool dfs(int pos, vector<vector<char>>& board) {
        if (pos >= space.size()) return true;  // 已经填写完毕
        int i, j;
        tie(i, j) = space[pos];
        int b = (i / 3) * 3 + j / 3;
        for (int k = 0; k < 9; k++) {
            // 尝试把数字填写到空格里面，如果有错，就回溯
            if (row[i][k] || col[j][k] || box[b][k]) continue;
            // 这个位置可以填写这个数字
            board[i][j] = '1' + k;
            row[i].set(k);
            col[j].set(k);
            box[b].set(k);
            if (dfs(pos + 1, board)) {
                return true;
            }
            // 执行了这一步，回溯
            board[i][j] = '.';
            row[i].reset(k);
            col[j].reset(k);
            box[b].reset(k);
        }
        return false;  // 所有的数字都不能填写
    }
};

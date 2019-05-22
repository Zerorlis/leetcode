#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        // 统计数量
        int numx = 0, numo = 0;
        for (auto& row : board) {
            for (auto c : row) {
                if (c == 'O') {
                    ++numo;
                } else if (c == 'X') {
                    ++numx;
                }
            }
        }
        if (!(numx - numo == 0 || numx - numo == 1)) {
            return false;  // 数量不对
        }
        // 检测胜负
        int winx = 0, wino = 0;
        // 横
        for (int i = 0; i < 2; i++) {
            if (board[i][0] != ' ' && board[i][0] == board[i][1] &&
                board[i][0] == board[i][2]) {
                if (board[i][0] == 'X') {
                    winx++;
                } else {
                    wino++;
                }
            }
        }
        // 竖
        for (int i = 0; i < 2; i++) {
            if (board[0][i] != ' ' && board[0][i] == board[1][i] &&
                board[0][i] == board[2][i]) {
                if (board[0][i] == 'X') {
                    winx++;
                } else {
                    wino++;
                }
            }
        }

        // 斜
        if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
            if (board[0][0] == 'X') {
                winx++;
            } else if (board[0][0] == 'O') {
                wino++;
            }
        }
        if (board[2][0] == board[1][1] && board[2][0] == board[0][2]) {
            if (board[2][0] == 'X') {
                winx++;
            } else if (board[2][0] == 'O') {
                wino++;
            }
        }

        if (winx && wino) return false;
        if (winx && !(numx - numo == 1)) return false;
        if (wino && !(numx == numo)) return false;
        return true;
    }
};

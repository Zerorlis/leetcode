#include <vector>
using namespace std;
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> last(1);  // 上一层
        vector<double> next(1);  // 下一层
        next[0] = (double)poured;
        for (int row = 0; row < query_row; row++) {
            swap(next, last);
            next.assign(row + 2, 0);
            bool has_next = false;
            for (int column = 0; column <= row; column++) {
                //第row层，流到row+1层
                double q = (last[column] - 1) / 2;
                if (q > 0) {
                    has_next = true;  // 还是有流到下一层
                    next[column] += q;
                    next[column + 1] += q;
                }
            }
            if (!has_next) return 0;
        }
        return min(1.0, next[query_glass]);
    }
};

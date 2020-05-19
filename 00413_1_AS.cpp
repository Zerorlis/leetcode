#include <vector>
using namespace std;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int res = 0;
        int lastNum = 0;  //在[0,i-1]之间，包括a[i-1]的等差数列的数量
        // 如果a[i]和a[i-1]构成等差数列，包括a[i]的等差数列的数量+1
        for (int i = 2; i < (int)A.size(); i++) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                lastNum++;
                res += lastNum;
            } else {
                lastNum = 0;
            }
        }
        return res;
    }
};

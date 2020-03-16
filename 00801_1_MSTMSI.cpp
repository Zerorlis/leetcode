#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        vector<int> change(A.size());
        vector<int> nochange(A.size());
        change[0] = 1;
        nochange[0] = 0;
        for (int i = 1; i < A.size(); i++) {
            if (A[i - 1] >= B[i] || B[i - 1] >= A[i]) {
                change[i] = change[i - 1] + 1;
                nochange[i] = nochange[i - 1];
            } else if (A[i] <= A[i - 1] || B[i] <= B[i - 1]) {
                change[i] = nochange[i - 1] + 1;
                nochange[i] = change[i - 1];
            } else {
                change[i] = min(change[i - 1], nochange[i - 1]) + 1;
                nochange[i] = min(change[i - 1], nochange[i - 1]);
            }
        }
        return min(change.back(), nochange.back());
    }
};

#include <ctime>
#include <random>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        if (A[0] == A[2]) return A[0];
        if (A[1] == A[3]) return A[1];
        if (A.size() < 20) {
            // 相邻的
            for (int i = 1; i < A.size(); i++) {
                if (A[i] == A[i - 1]) return A[i];
            }
            return A[0];  // 理论上不会走到这一步
        }
        // 随机方法，每次有1/2的几率抽中这个重复数字
        default_random_engine e(time(0));                       // 种子
        uniform_int_distribution<unsigned> u(0, A.size() - 1);  // 随机数发生器
        unordered_set<int> s;

        while (true) {
            int i = A[u(e)];
            if (!s.insert(i).second) return i;
        }
    }
};

#include <string>
using namespace std;
class Solution {
public:
    int minAddToMakeValid(string S) {
        int bal = 0;
        int ans = 0;
        for (auto c : S) {
            bal += (c == '(' ? 1 : -1);
            // 如果出现负数，说明)多一个，需要添加一个(
            if (bal == -1) {
                bal = 0;
                ans++;
            }
        }
        // 如果bal>0,说明(多
        return ans + bal;
    }
};

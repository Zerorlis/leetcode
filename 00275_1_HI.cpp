#include <vector>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int left = 0;
        int right = citations.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (citations[mid] == (int)citations.size() - mid) {
                return citations.size() - mid;
            } else if (citations[mid] < (int)citations.size() - mid) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return citations.size() - left;
    }
};

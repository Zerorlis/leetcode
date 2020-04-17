#include <stack>
#include "list.h"
using namespace std;
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> num1;
        stack<int> num2;
        while (l1) {
            num1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            num2.push(l2->val);
            l2 = l2->next;
        }
        bool carry = false;  //进位
        ListNode* ans = NULL;
        while (!num1.empty() || !num2.empty() || carry) {
            int n1 = 0;
            int n2 = 0;
            if (!num1.empty()) {
                n1 = num1.top();
                num1.pop();
            }
            if (!num2.empty()) {
                n2 = num2.top();
                num2.pop();
            }
            int val = n1 + n2 + carry;
            carry = (val > 9);
            ListNode* nowNode = new ListNode(val % 10);
            nowNode->next = ans;
            ans = nowNode;
        }
        return ans;
    }
};

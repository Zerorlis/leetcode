/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        int carry = 0;
        ListNode* end = res;
        while (l1 != NULL || l2 != NULL) {
            int i1 = l1 ? l1->val : 0;
            int i2 = l2 ? l2->val : 0;
            sum = i1 + i2 + carry;
            end->next = new ListNode(sum / 10);
            carry = sum / 10;
            end = end->next;
            if (!l1) l1 = l1->next;
            if (!l2) l2 = l2->next;
        }
        if (carry > 0) {
            end->next = new ListNode(1);
        }
        return dummyHead->next;
    }
};

//双指针法，每次都走一步，最后一定会相遇。如果走到最后，就到另一个链表的头
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        while (p1 != p2) {
            p1 = (p1 == NULL ? headB : p1->next);
            p2 = (p2 == NULL ? headA : p2->next);
        }
        return p1;
    }
};

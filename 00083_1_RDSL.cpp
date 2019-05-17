/**
 * @file 00083_1_RDSL.cpp
 * @brief 应该挺简单的，用两个指针指着，一个是下一个节点
 * @author Zerorlis
 * @version 0.1
 * @date 2019-05-17
 */
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode* a = head;
        ListNode* b = head->next;
        while (b != NULL) {
            if (a->val == b->val) {
                b = b->next;
                delete a->next;
                a->next = b;
            } else {
                a = b;
                b = b->next;
            }
        }
        return head;
    }
};

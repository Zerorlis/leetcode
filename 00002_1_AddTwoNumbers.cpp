/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * 失败，因为int太小，long long也不行
 */

#include <stdio.h>
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int i1 = toInt(l1);
        int i2 = toInt(l2);
        return toListNode(i1 + i2);
    }
    int toInt(ListNode* l) {
        int i = 0;  // 值
        int d = 1;  // 位数
        while (l != NULL) {
            i += l->val * d;
            d = d * 10;
            l = l->next;
        }
        return i;
    }
    ListNode* toListNode(int i) {
        ListNode* node = NULL;
        ListNode* end = NULL;
        while (i != 0) {
            ListNode* newNode = new ListNode(i % 10);
            if (node == NULL) {
                node = newNode;
            } else {
                end->next = newNode;
            }
            end = newNode;
            i = i / 10;
        }
        return node;
    }
};

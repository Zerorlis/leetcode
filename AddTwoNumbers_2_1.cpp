/**
 * 尝试打算线写个暴力的方法
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 要构建新的nodelist，感觉循环一次就够
        ListNode* rp = new ListNode(0);  // 当前循环的时候该放的位置
        ListNode* p = rp;
        ListNode* lp = NULL;  // 指向当前节点的前一个
        bool isAdd = false;   // 是否进位
        while (l1 != NULL && l2 != NULL) {
            p->val = l1->val + l2->val;
            if (isAdd) {
                p->val++;
                isAdd = false;
            }
            if (p->val >= 10) {
                p->val = p->val % 10;  //可能进位
                isAdd = true;
            }

            // 算完成了，为下一步做准备
            p->next = new ListNode(0);
            lp = p;
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != NULL) {
            p->val = l1->val;
            if (isAdd) {
                p->val++;
                isAdd = false;
            }
            if (p->val >= 10) {
                p->val = p->val % 10;  //可能进位
                isAdd = true;
            }
            p->next = new ListNode(0);
            lp = p;
            p = p->next;
            l1 = l1->next;
        }
        while (l2 != NULL) {
            p->val = l2->val;
            if (isAdd) {
                p->val++;
                isAdd = false;
            }
            if (p->val >= 10) {
                p->val = p->val % 10;  //可能进位
                isAdd = true;
            }
            p->next = new ListNode(0);
            lp = p;
            p = p->next;
            l2 = l2->next;
        }
        // 循环结束，现在要试着删除多于的一个开头
        if (isAdd) {
            p->val = 1;
        } else {
            lp->next = NULL;
            delete p;
        }
        return rp;
    }
};
;

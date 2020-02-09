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
    ListNode* swapPairs(ListNode* head) {
        // 在纸上画图模拟后，特别简单
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        auto p = dummy;
        while(p->next && p->next->next) {
            auto a = p->next, b = p->next->next;
            p->next = b;
            a->next = b->next;
            b->next = a;
            p = a;
        }

        return dummy->next;
    }
};

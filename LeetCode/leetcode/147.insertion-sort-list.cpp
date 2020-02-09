/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
 */

// @lc code=start
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
    ListNode* insertionSortList(ListNode* head) {
        auto dummy = new ListNode(-1);
        auto p = dummy, q = head;
        // q:4->1->3->2
        // p:1->2->3->4
        while(q != NULL) {
            // insert element every time
            p = dummy;
            while(p->next != NULL) {
                if (q->val < p->next->val) {
                    auto tmp = q->next;
                    q->next = p->next;
                    p->next = q;
                    q = tmp;
                    break; 
                }
                p = p->next;
            }

            if (p->next == NULL) {
                auto tmp = q->next;
                q->next = NULL;
                p->next = q;
                q = tmp;
            }
        }
        return dummy->next;
    }
};
// @lc code=end


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto dummy = new ListNode(-1);
        dummy->next = head;

        auto first = dummy;
        auto second = dummy;
        while(n --) {
            first = first->next;
        }

        while(first->next) {
            first = firsr->next;
            second = second->next;
        }

        second->next = second->next->next;

        return dummy->next;
    }
};



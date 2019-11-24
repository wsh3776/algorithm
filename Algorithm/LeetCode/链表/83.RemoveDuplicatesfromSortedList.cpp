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
        ListNode *cur = head;
        if (!cur || !cur -> next) return head;
        while(cur -> next) { // cur 和 cur -> next 有区别
            if( cur -> val == cur -> next -> val) {
                cur -> next = cur -> next -> next;
            } else {
                cur  = cur -> next;
            }
        }

        return head;
    }
};

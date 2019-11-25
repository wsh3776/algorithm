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
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        auto a = head, b = head->next, c = head;
        
        // 1 2 3 4 5 NULL
        // 5 4 3 2 1 NULL
        while(b) {  // Draw a picture on the paper, and then it will be very easy.
           c = b->next;
           b->next = a;
           a = b;
           b = c;
        }

        head->next = NULL;

        return a;
    }
};

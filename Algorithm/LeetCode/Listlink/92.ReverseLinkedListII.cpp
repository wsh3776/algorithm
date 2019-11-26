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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) return head;
        auto dummy = new ListNode(-1); // Reduced boundary discussion
        dummy->next = head; 
        auto ft = dummy, sd = dummy;
        for (int i = 0; i < m - 1; i ++) ft = ft->next;
        for (int i = 0; i < n; i ++) sd = sd->next;
        auto a = ft->next; // similar to I:head
        auto d = sd->next; // similar to I:NULL
        
        // Reverse Linked List template
        auto b = a->next;
        while(b != d) { // b->next is wrong, cause b = c after while;
            auto c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
        
        // Connect the fore and aft
        ft->next->next = b;
        ft->next = sd;
       
        return dummy->next;
    }
};

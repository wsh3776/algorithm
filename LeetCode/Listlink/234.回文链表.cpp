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
    bool isPalindrome(ListNode* head) {
        // 1 2 3 3 2 1 NULL
        if (!head || !head->next) return true;
        auto fast = head, slow = head, p = head;
        while(fast) {
            slow = slow->next;
            fast = fast->next;
            if(!fast) break; 
            fast = fast->next;
        } 
        // Now slow is the head of half Link
        auto a = slow, b = slow;
        b = a->next;
        while(b) {
            auto c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
    
        slow->next = NULL;
        
        auto q = a;
        while(q) {
            if(p->val != q->val) return false;
            p = p->next;
            q = q->next;
        }

        return true;
    }
};
// https://leetcode-cn.com/problems/rotate-list/
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;

        int n = 0;
        for (ListNode *p = head; p; p = p->next) n ++;

        k %= n;
    
        // two points move together
        auto first = head, second = head;
        while(k --) first = first->next;
        while(first -> next) {
            first = first->next;
            second = second->next;
        }
    
        // Draw a clear picture 
        first->next = head;
        head = second->next;
        second->next = NULL;
        
        return head;
    }
};


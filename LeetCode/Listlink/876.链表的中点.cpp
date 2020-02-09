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
    ListNode* middleNode(ListNode* head) {
        auto fast = head, slow = head;
        
        // odd-even 快慢指针法找链表的中点
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return slow;
    }
};
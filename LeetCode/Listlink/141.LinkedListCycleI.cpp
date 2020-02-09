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
    bool hasCycle(ListNode *head) {
        auto fast = head, slow = head;
        while(fast){
            fast = fast->next;
            slow = slow->next;
            if (fast) fast = fast->next;
            else return false;
            
            if (fast == slow) return true;
        }

        return false;
    }
};

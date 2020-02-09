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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // Recursion
        // 1 2 5 NULL
        //   3 4 7 NULL    
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        // 可以理解为递归函数已经给你做好了
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
        
        return nullptr;
    }
};

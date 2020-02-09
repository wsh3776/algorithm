算法：
1.Two pointers do not intersect 
p and q both move a+b step, then turn into NULL.
2.Two pointers intersect
p adn q both move a+b+c step, then they will meet.


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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // p and q both move a + b + c
        auto p = headA, q = headB;
        while(p != q) {
            if (p) p = p->next;
            else p = headB;
            if (q) q = q->next;
            else q = headA;
        }

        return p;
    }
};

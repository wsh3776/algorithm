/**
 *    @Author: Wilson79
 *    @Datetime: 2019年12月28日 星期六 14:40:26
 *    @Filename: new.cpp
 */

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int t = 0;
        auto res = new ListNode(-1);

        auto q = res;

        while(l1 || l2) {
            if (l1) {
                t += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                t += l2->val;
                l2 = l2->next;
            }
            auto p = new ListNode(t % 10);
            t /= 10;
            q -> next = p;
            q = p;


        }
        q->next = NULL;

        return res->next;
    }
};
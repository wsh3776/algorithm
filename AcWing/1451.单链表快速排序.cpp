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
    ListNode *getTail(ListNode *head) {
        while (head->next)
            head = head->next;
        return head;
    }

    ListNode *quickSortList(ListNode *head) {
        // 遍历链表，按照三种情况分别加到三个链表中

        // 空结点或单结点
        if (!head || !head->next) return head;
        ListNode *lhead = new ListNode(-1), *mhead = new ListNode(-1), *rhead = new ListNode(-1);
        auto left = lhead, mid = mhead, right = rhead;

        // 遍历链表
        int x = head->val;
        for (auto p = head; p; p = p->next) {
            if (p->val < x)
                left = left->next = p;
            else if (p->val == x)
                mid = mid->next = p;
            else
                right = right->next = p;
        }

        // 得到三个链表，递归左边和右边链表
        left->next = mid->next = right->next = nullptr;
        lhead->next = quickSortList(lhead->next);
        rhead->next = quickSortList(rhead->next);
        // 拼接链表
        getTail(lhead)->next = mhead->next;
        getTail(mhead)->next = rhead->next;

        auto re = lhead->next;
        delete lhead;
        delete mhead;
        delete rhead;

        return re;
    }
};
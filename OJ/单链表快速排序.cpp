#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x)
        : val(x)
        , next(NULL) {
    }
};

ListNode *createList() {
    int d;
    cin >> d;
    if (d == -1) return NULL;
    ListNode *head = new ListNode(d);
    head->next = createList();
    return head;
}

ListNode *getTail(ListNode *head) {
    while (head->next)
        head = head->next;
    return head;
}

ListNode *quickSort(ListNode *head) {
    if (!head || !head->next) return head;
    // 遍历链表，根据值分成三段
    auto lhead = new ListNode(-1), mhead = new ListNode(-1), rhead = new ListNode(-1);
    auto left = lhead, mid = mhead, right = rhead;
    int x = head->val;
    for (auto p = head; p; p = p->next) {
        if (p->val < x)
            left = left->next = p;
        else if (p->val == x)
            mid = mid->next = p;
        else if (p->val > x)
            right = right->next = p;
    }

    left->next = mid->next = right->next = NULL;
    // 递归第一段和第二段
    lhead->next = quickSort(lhead->next);
    rhead->next = quickSort(rhead->next);
    // 然后拼接这三段
    getTail(lhead)->next = mhead->next;
    getTail(mhead)->next = rhead->next;

    auto res = lhead->next;
    delete lhead;
    delete mhead;
    delete rhead;

    return res;
}

int main() {
    auto head = createList();
    head = quickSort(head);

    while (head) {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}
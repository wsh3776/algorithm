#include <iostream>
#include <initializer_list>

using namespace std;

// 定义链表结点
typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
} ListNode;

// 创建单链表(返回头结点)
ListNode *create_linkedlist(initializer_list<int> lst) {
    auto iter = lst.begin();
    ListNode *head = lst.size() ? new ListNode(*iter++) : nullptr;
    for (ListNode *cur = head; iter != lst.end(); cur = cur->next)
        cur->next = new ListNode(*iter++);
    return head;
}

// 单链表正向输出(递归)
void printList(ListNode *head) {
    if (head == nullptr) return;
    cout << head->val << " ";
    printList(head->next);
}

// 单链表反向输出(递归)
void printReverse(ListNode *head) {
    if (head == nullptr) return;
    printReverse(head->next);
    cout << head->val << " ";
}

// 删除单链表
void clear(ListNode *head) {
    while (head) {
        ListNode *del = head;
        head = head->next;
        delete del;
    }
}

// 翻转链表
ListNode *reverseList(ListNode *head) {
    auto a = head, b = head;
    if (!a || !a->next) return a;
    b = a->next;
    while(b) {
        auto c = b->next;
        b->next = a;
        a = b;
        b = c;
    }

    head->next = NULL;
    head = a;
    return head;
}


int main() {
    ListNode *head = create_linkedlist({1, 4, 5, 3, 2, 6, 7});
    printList(head);
    cout << endl;
    printList(reverseList(head));
    clear(head);
}
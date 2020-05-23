#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL) {
    }
};

// create tree by preorder, -1 means NULL
TreeNode *createTree() {
    int d;
    cin >> d;
    if (d == -1) return NULL;
    TreeNode *root = new TreeNode(d);
    root->left = createTree();
    root->right = createTree();
    return root;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x)
        : val(x)
        , next(NULL) {
    }
};

// create linked list, -1 means NULL
ListNode *createList() {
    int d;
    cin >> d;
    if (d == -1) return NULL;
    ListNode *head = new ListNode(d);
    head->next = createList();
    return head;
}

bool isSame(ListNode *head, TreeNode *root) {
    if (head == NULL) return true;
    if (root == NULL) return false;

    if (root->val != head->val) return false;

    return isSame(head->next, root->left) || isSame(head->next, root->right);
}

bool isSubPath(ListNode *head, TreeNode *root) {
    if (!head) return true;
    if (!root) return false;
    if (isSame(head, root)) return true;

    return isSubPath(head, root->left) || isSubPath(head, root->right);
}

int main() {
    // Tree: 1 2 -1 -1 3 4 -1 -1 -1
    // List: 1 3 -1
    TreeNode *root = createTree();
    ListNode *head = createList();

    if (isSubPath(head, root))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
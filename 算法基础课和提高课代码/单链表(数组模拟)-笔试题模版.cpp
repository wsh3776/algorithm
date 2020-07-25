// 在笔试题中需要用到单链表的数组模拟，因为 new 操作很慢

#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e5 + 7;

// head 表示头结点的下标（竖着画）
// e[i] 表示结点 i 的值
// ne[i] 表示结点 i 的 next 指针是多少
// idx 存储当前已经用到了哪个点
int head, idx, e[N], ne[N];

// 初始化
void init() {
    head = -1; // head = -1 表示当前头结点是空节点(-1)
    idx = 0;   // idx = 0 表示从 0 号结点开始用
}

// 头插法：将 x 插到头结点head后面
void add_to_head(int x) {
    e[idx] = x;
    ne[idx] = head; // 先连
    head = idx;     // 后断
    idx++;          // 当前 idx 结点已经用过了
}

// 尾插法：将 x 插到尾结点idx-1后面（适用范围小，必须依次进行插入操作）
void add_to_end(int x) {
    e[idx] = x;
    ne[idx] = -1; // 先连

    if (!idx)
        head = idx; // 后断
    else
        ne[idx - 1] = idx; // 后断

    idx++;
}


// 将 x 插到下标是k的节点后面
void add(int k, int x) {
    e[idx] = x;      // 设置 val 值
    ne[idx] = ne[k]; // 先连
    ne[k] = idx;     // 后断
    idx++;
}

// 将下标是 k 的结点后面的结点删除
void remove(int k) {
    ne[k] = ne[ne[k]];
}

int main() {
    int m;
    cin >> m;

    init();

    while (m--) {
        int k, x;
        string s;
        cin >> s;
        if (s == "H") {
            cin >> x;
            add_to_head(x);
        } else if (s == "I") {
            cin >> k >> x;
            add(k - 1, x);
        } else if (s == "D") {
            cin >> k;
            if (!k)
                head = ne[head];
            else
                remove(k - 1);
        }
    }

    for (int i = head; i != -1; i = ne[i]) {
        cout << e[i] << " ";
    }

    return 0;
}
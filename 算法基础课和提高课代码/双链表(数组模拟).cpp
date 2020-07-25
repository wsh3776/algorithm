// 双链表(数组模拟)
// https://www.acwing.com/problem/content/829/
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100010;

int e[N], l[N], r[N], idx;

// 初始化
void init() {
    // 结点0表示左哨兵，1表示右哨兵
    r[0] = 1, l[1] = 0;
    idx = 2; // 下标0和1已经被用过
}

// 插入元素 - 在下标为k的点的右边插入x
void add(int k, int x) {
    e[idx] = x;

    r[idx] = r[k]; // 先连
    l[idx] = k;    // 先连

    l[r[k]] = idx; // 后断 (这行必须在r[k] = idx前面)
    r[k] = idx;    // 后断
    idx ++;
}
// 注：插入元素 - 在下标为k的点的左边插入x，只需 add(l[k], x);

// 删除元素 - 删除下标为k的结点
void remove(int k) {
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

int main() {
    int m;
    cin >> m;

    init();

    // L : add(0, x)
    // R : add(l[1], x)
    // D : remove(k + 1, x) // 第 k 个插入的数，下标为 k + 1
    // IL : add(l[k + 1], x)
    // IR : add(k + 1, x)
    while (m--) {
        int x, k;
        string s;
        cin >> s;
        if (s == "L") {
            cin >> x;
            add(0, x);
        } else if (s == "R") {
            cin >> x;
            add(l[1], x);
        } else if (s == "D") {
            cin >> k;
            remove(k + 1);
        } else if (s == "IL") {
            cin >> k >> x;
            add(l[k + 1], x);
        } else if (s == "IR") {
            cin >> k >> x;
            add(k + 1, x);
        }
    }

    // 从左往右遍历双链表
    for (int i = r[0]; i != 1; i = r[i]) {
        cout << e[i] << " ";
    }

    return 0;
}
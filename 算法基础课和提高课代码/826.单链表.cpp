// https://www.acwing.com/problem/content/description/828/

// 用数组模拟单链表（静态链表）
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e5 + 7;

int head, idx, e[N], ne[N];

void init() {
    head = -1, idx = 0;
}

void add_to_head(int x) {
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx ++;
}

void add(int k, int x) {
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx ++;
}

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
            if (!k) head = ne[head];
            else remove(k - 1);
        }
    }

    for (int i = head; i != -1; i = ne[i]) {
        cout << e[i] << " ";
    }

    return 0;
}
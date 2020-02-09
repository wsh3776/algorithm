// 2020年1月30日 星期四 18:46:27
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
const int N = 100010;
int h[N], size_;

// 值变化，需往下维护
void down(int u) {
    int t = u; // t记录最小值
    if (2 * u <= size_ && h[2 * u] < h[t]) t = 2 * u; // 左儿子存在，且值比父亲小
    if (2 * u + 1 <= size_ && h[2 * u + 1] < h[t]) t = 2 * u + 1;
    if (t != u) {
        swap(h[t], h[u]);
        down(t);
    }
    return;
}

// 值变化，需往上维护
void up(int u) {
    if (u / 2 > 0 && h[u / 2] > h[u]) {
        swap(h[u / 2], h[u]);
        up(u / 2);
    }
    return;
}


int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> h[i]; // 下标从1开始
    size_ = n;

    // 初始化堆
    for (int i = n / 2; i > 0; i --) down(i); // O(n)复杂度

    // h[3] = 100;
    // up(3), down(3);

    h[++size_] = -2;
    up(size_);
    while(m --) {
        cout << h[1] << " ";
        h[1] = h[size_];
        size_ --;
        down(1); // 值变大时需要down()操作
    }


    return 0;
}
// 三种操作都包含了——特别是维护每个集合的个数
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int N = 100010;

int n, m;
int p[N], size[N]; // 只记录根结点的size

int find(int x) {  // 返回x的祖宗节点 + 路径压缩
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif

    string c; // 用string, 不会遇到M，Q1，Q2这种询问的麻烦
    int a, b;
    cin >> n >> m;

    // 初始化
    for (int i = 1; i <= n; i ++) {
        p[i] = i;
        size[i] = 1;
    }

    // 分三种情况
    for (int i = 0; i < m; i ++) {
        cin >> c;
        if (c == "C") {
            cin >> a >> b;
            if (find(a) != find(b)) {   // 如果已经连通了，就不用再加结点数了，因为我们只看根的size
                size[find(b)] += size[find(a)];
            }

            p[find(a)] = find(b);  // union操作 合并
        } else if (c == "Q1") {
            cin >> a >> b;
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        } else {
            cin >> a;
            cout << size[find(a)] << endl;
        }
    }
    return 0;
}
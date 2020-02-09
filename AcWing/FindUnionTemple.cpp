// yxc版 代码简练 用数组
#include <iostream>
#include <cstdio>

using namespace std;

const int N = 100010;

int n, m;
int p[N];

int find(int x) {  // 返回x的祖宗节点 + 路径压缩
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    char c;
    int a, b;
    cin >> n >> m;
    
    // 初始化1->1 ... n->n 
    for (int i = 1; i <= n; i ++) {
        p[i] = i;
    }
    
    for (int i = 0; i < m; i ++) {
        cin >> c >> a >> b;
        if (c == 'M') p[find(a)] = find(b);  // union操作 合并
        else {
            if (find(a) == find(b))
                cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}


// corner版
class UnionFind {
public:
    vector<int> father;
    UnionFind(int num) {
        for (int i = 0; i < num; i ++) {
            father.push_back(i);
        }
    }

    int Find(int n) {
        if(father[n] == n) return n;
        father[n] = Find(father[n]);
        return father[n];
    }

    bool Union(int a, int b) {
        int fa = Find(a);
        int fb = Find(b);
        father[fb] = fa;
        return fa == fb;   // 判断两个点是否连通
    }
};
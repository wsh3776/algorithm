// yxc版 简练
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int N = 100010;

int n, m;
int p[N];

int find(int x)
{ // 返回x的祖宗节点 + 路径压缩
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main() {
    #ifdef ONLINE_JUDGE
    #else
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif

    string c; // 用string, 不会遇到M，Q1，Q2这种询问的麻烦
    int a, b;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i ++) {
        p[i] = i;
    }
    
    for (int i = 0; i < m; i ++) {
        cin >> c >> a >> b;
        if (c == "M") p[find(a)] = find(b);  // union操作 合并
        else {
            if (find(a) == find(b))
                cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}


// // corner版 用了UnionFind类 vector初始化遇到0比较麻烦
// #include <iostream>
// #include <cstdio>
// #include <vector>

// using namespace std;

// class UnionFind {
// public:
//     vector<int> father;

//     UnionFind(int num) {
//         for (int i = 0; i <= num; i ++) {
//             father.push_back(i);
//         }
//     }

//     int Find(int n) {
//         if (father[n] == n) return n;
//         father[n] = Find(father[n]);
//         return father[n];
//     }

//     void Union(int a, int b) {
//         int fa = Find(a);
//         int fb = Find(b);
//         father[fb] = fa;
//     }
// };


// int main() {
//     int n, m;
//     char c;
//     int a, b;
//     cin >> n >> m;
//     UnionFind UF(n);
//     for (int i = 0; i < m; i ++) {
//         cin >> c >> a >> b;
//         if (c == 'M') UF.Union(a, b);
//         else {
//             if (UF.Find(a) == UF.Find(b)) {
//                 cout << "Yes" << endl;
//             } else {
//                 cout << "No" << endl;
//             }
//         }
//     }
//     return 0;
// }
/**
 *    @Author: Wilson79
 *    @Datetime: 2019年12月22日 星期日 11:43:37
 *    @Filename: 238.银河英雄传说.cpp
 */

// 用size去维护每个连通块的个数，d[x]表示x到当前祖宗结点的距离，d[x]在find一次后会更新
// 每次把size加到pa上，这样整个pa连通块上的点的d[i],之后更新时都会加上这个size
    
#include <iostream>

using namespace std;

const int N = 30010;

int p[N], d[N], size[N];
int a, b;

int find(int x) {
    if (p[x] != x) {
        int root = find(p[x]); // 递归到底
        d[x] += d[p[x]]; // 从底往回，更新距离
        p[x] = root; // 压缩路径
    }
    return p[x];
}


int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < N; i ++) {
        p[i] = i;
        size[i] = 1;
        d[i] = 0;
    }

    while(T --) {
        char op[2]; // 用scanf读单个字符的巧妙写法
        scanf("%s%d%d", op, &a, &b);

        if (op[0] == 'M') {
            int pa = find(a), pb = find(b);
            d[pa] += size[pb]; // 把size加到pa结点即可，这样原pa连通块上的距离在之后find时都会加上这个size
            size[pb] += size[pa];
            p[pa] = pb;
        } else {
            int pa = find(a), pb = find(b);
            // 必须find一次,才能把d[a],d[b]更新到最新
            if (pa != pb) cout << "-1" << endl;
            else {
                cout << max(abs(d[a] - d[b]) - 1, 0) << endl;
            }
        }
    }


    return 0;
}
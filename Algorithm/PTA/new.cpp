按距离根节点从近到远的顺序，把这条x到根节点路径上的点的距离都更新一遍
食物链和银河战舰的传说  好题


如果用scanf读取单个字符时建议用字符数组去读取
因为C++中 % s会自动把换行符或空格过滤掉 如读取M   2 3 ，用char op[2]读取，间隔多个空格也OK

% c连续读取，会空格或换行
% s会自动把换行符或空格过滤掉
% d会自动把换行符或空格过滤掉


读取数据:
4
M  2 3
C   1 2
M 2 4
C 4 2

#include <bits/stdc++.h>

using namespace std;

const int N = 30010;

int m;
int p[N], size[N], d[N];

int find(int x) {
    if (p[x] != x) {
        int root = find(p[x]);
        d[x] += d[p[x]];
        p[x] = root;
    }
    return p[x];
}

int main() {
    scanf("%d", &m);

    for (int i = 1; i < N; i ++ ) {
        p[i] = i;
        size[i] = 1;
    }

    // 在用到scanf读取单个字符时，普通做法容错率很低要用getchar读取换行
    while (m -- ) {
        char op;
        int a, b;
        
        getchar(); // 因为%d以空格或换行为结束标准，不会读取空白字符

        scanf("%c%d%d", &op, &a, &b); // %c连续读取，不忽略空格或换行，%d跳过空格或换行读取
        if (op == 'M') {
            int pa = find(a), pb = find(b);
            d[pa] = size[pb];
            size[pb] += size[pa];
            p[pa] = pb;
        } else {
            int pa = find(a), pb = find(b);
            if (pa != pb) puts("-1");
            else printf("%d\n", max(0, abs(d[a] - d[b]) - 1));
        }
    }

    return 0;
}


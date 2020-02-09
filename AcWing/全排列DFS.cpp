// 2020年1月13日 星期一 10:29:57
#include <iostream>

using namespace std;

const int N = 10;

int n;
int path[N];
bool st[N]; // 用来判断搜下一层的位置 可以选什么

// 通过u判断层数 u = 0表示第1层
// DFS就是把所有情况搜一遍，也可以加个判断条件找最优（剪枝）

void dfs(int u) {
    if (u == n) {
        for (int i = 1; i <= n; i ++ ) printf("%d ", path[i]);
        puts("");
        return;
    }

    for (int i = 1; i <= n; i ++) // for循环有几个if条件成立，当前结点就有几个分支
        if (!st[i]) {   
            path[u + 1] = i;      // 一开始u = 0，u + 1表示从第2层开始填数，具体可以看图
            st[i] = true;         // true表示i用过了
            dfs(u + 1);           // 对u + 1位置进行填数，递归
            path[u + 1] = 0;      // 这步可有可无，因为会被覆盖
            st[i] = false;        // 恢复现场（方便下一个分支能正常搜索）
        }
}

int main() {
    cin >> n;

    dfs(0); // 0表示从树根全是空位开始

    return 0;
}
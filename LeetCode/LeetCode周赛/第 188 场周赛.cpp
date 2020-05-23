/*
 * @Date: 2020-05-10 10:22:06
 * @FilePath: /Wilson79/Algorithm/LeetCode/LeetCode周赛/第 188 场周赛.cpp
 * @LastEditors: cs_shwei@163.com
 * @LastEditTime: 2020-05-16 08:52:31
 */

// https://leetcode-cn.com/contest/weekly-contest-188/ranking/

// 5404. 用栈操作构建数组
class Solution {
public:
    vector<string> buildArray(vector<int> &target, int n) {
        vector<string> res;
        for (int i = 1, j = 0; i <= target[target.size() - 1]; i++) {
            if (target[j] != i) {
                res.push_back("Push");
                res.push_back("Pop");
            } else {
                res.push_back("Push");
                j++;
            }
        }
        return res;
    }
};

// 5405. 形成两个异或相等数组的三元组数目
class Solution {
public:
    // 暴力超时
    int solve(int m, int n, vector<int> &arr) {
        int res = 0;
        for (int i = m; i <= n; i++) {
            res ^= arr[i];
        }
        return res;
    }
    int countTriplets(vector<int> &arr) {
        int n = arr.size(), cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j; k < n; k++) {
                    if (solve(i, j - 1, arr) == solve(j, k, arr)) cnt++;
                }
            }
        }
        return cnt;
    }
};

class Solution {
public:
    // 前缀和思想 (a ^ b) ^ a = b;
    int v[307];

    int countTriplets(vector<int> &arr) {
        int n = arr.size(), cnt = 0;

        v[0] = 0;
        for (int i = 1; i <= n; i++) {
            v[i] = v[i - 1] ^ arr[i - 1];
        }

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j; k < n; k++) {
                    if ((v[i] ^ v[j]) == (v[j] ^ v[k + 1])) cnt++;
                }
            }
        }
        return cnt;
    }
};

// 5406. 收集树上所有苹果的最少时间
// 别人的代码 DFS
class Solution {
public:
#define MAX 200005
    int cnt;
    int head[MAX], vet[MAX], Next[MAX], ans[MAX], vis[MAX];
    void add(int x, int y) {
        cnt++;
        Next[cnt] = head[x];
        head[x] = cnt;
        vet[cnt] = y;
    }

    void dfs(int x, int fa) {
        ans[x] = 0;
        for (int i = head[x]; i; i = Next[i]) {
            int v = vet[i];
            if (v == fa) continue;
            dfs(v, x);
            if (ans[v] || vis[v]) {
                ans[x] += ans[v] + 2;
            }
        }
    }
    int minTime(int n, vector<vector<int>> &e, vector<bool> &v) {
        memset(head, 0, sizeof(head));
        cnt = 0;
        memset(ans, 0, sizeof(ans));
        for (int i = 0; i < e.size(); i++) {
            add(e[i][0], e[i][1]), add(e[i][1], e[i][0]);
        }
        for (int i = 0; i < v.size(); i++) {
            vis[i] = v[i];
        }
        dfs(0, -1);
        return ans[0];
    }
};
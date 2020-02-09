// leetcode547_FriendCircles
// 版本一 UnionFind初始化
class UnionFind {
public:
    vector<int> father;
    UnionFind(int num) {
        for (int i = 0; i < num; i ++) {
            father.push_back(i);
        }
    }

    int Find(int n) {
        // 递归 + 路径压缩
        if(father[n] == n) return n;
        father[n] = Find(father[n]);
        return father[n];
    }

    void Union(int a, int b) {
        int fa = Find(a); // 2的原老大是1
        int fb = Find(b); // 4的原老大是3
        father[fb] = fa;   // 让3指向1
    }
};


class Solution {
public:
    int findCircleNum(vector<vector<int>> &M) {
        int n = M.size();
        UnionFind UF(n);
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (M[i][j] == 1) UF.Union(i, j);
            }
        }

        int res = 0;
        for (int i = 0; i < n; i ++) {
            if (UF.Find(i) == i) {
                res ++;
            }
        }

        return res;
    }
};


// 版本二 father定义成全局
vector<int> father;
class UnionFind {
public:

    int Find(int n) {
        // 递归 + 路径压缩
        if(father[n] == n) return n;
        father[n] = Find(father[n]);
        return father[n];
    }

    void Union(int a, int b) {
        int fa = Find(a); // 2的原老大是1
        int fb = Find(b); // 4的原老大是3
        father[fb] = fa;   // 让3指向1
    }
};


class Solution {
public:
    int findCircleNum(vector<vector<int>> &M) {
        int n = M.size();

        for (int i = 0; i < n; i ++) {
            father.push_back(i);
        }

        UnionFind UF;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (M[i][j] == 1) UF.Union(i, j);
            }
        }

        int res = 0;
        for (int i = 0; i < n; i ++) {
            if (UF.Find(i) == i) {
                res ++;
            }
        }

        father.clear(); // 多组数据时必须清空father

        return res;
    }
};
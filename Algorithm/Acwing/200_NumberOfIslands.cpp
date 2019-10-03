// 并查集
class UnionFind {
public:
    vector<int> father;
    UnionFind(int num) {
        for (int i = 0; i < num; i ++) {
            father.push_back(i);
        }
    }

    int Find(int n) {
        if (father[n] == n) return n;
        father[n] = Find(father[n]);
        return father[n];
    }

    void Union(int a, int b) {
        int fa = Find(a);
        int fb = Find(b);
        father[fb] = fa;
    }
};

int encode(int i, int j, int m) {
    return i * m + j;
}

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        if (!grid.size() || !grid[0].size()) return 0;
        int n = grid.size(), m = grid[0].size();

        UnionFind UF(n * m);

        // 合并
        int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (grid[i][j] == '1') {
                    for (int d = 0; d < 4; d ++) {
                        int x = dx[d] + i, y = dy[d] + j;
                        if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '1') {
                            UF.Union(encode(i, j, m), encode(x, y, m));
                        }
                    }
                }
            }
        }

        // 查找
        int res = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (grid[i][j] == '1' && UF.Find(encode(i, j, m))== encode(i, j, m)) {
                    res ++;
                }
            }
        }
        return res;
    }
};




// dfs算法
void dfs(vector<vector<char>> &grid, int a, int b) {

    //因为要修改原来的grid，所以这里必须用引用
    int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
    int m = grid.size(), n = grid[0].size();

    grid[a][b] = '0';
    for (int i = 0; i < 4; i++) {
        int x = a + dx[i], y = b + dy[i];
        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1') {
            dfs(grid, x, y);
        }
    }
    return;
}

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        int ans = 0;
        if (!grid.size() || !grid[0].size()) return 0;

        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
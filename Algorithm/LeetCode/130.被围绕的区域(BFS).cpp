/**
 *    @Author: Wilson79
 *    @Datetime: 2019年12月15日 星期日 22:25:33
 *    @Filename: 130.被围绕的区域.cpp
 */

// 把与边界的o连通的st[a][b] = true,并仍填充o
// 而内部的用x去填充
class Solution {
public:
#define x first
#define y second
    static const int N = 200;
    typedef pair<int, int> PII;

    PII q[N * N];
    bool st[N][N];

    void bfs(int sx, int sy, vector<vector<char>> &board, char c) {
        int hh = 0, tt = 0;
        int n = board.size(), m = board[0].size();
        q[0] = {sx, sy};
        st[sx][sy] = true;
        board[sx][sy] = c; // 变色问题要注意第一个也要变

        while(hh <= tt) {
            auto t = q[hh ++];
            int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
            for (int i = 0; i < 4; i ++) {
                int a = t.x + dx[i], b = t.y + dy[i];

                if (a < 0 || a >= n || b < 0 || b >= m) continue;
                if (board[a][b] == 'X' || st[a][b]) continue;
                board[a][b] = c;
                q[++ tt] = {a, b};
                st[a][b] = true;

            }
        }
        return;
    }

    void solve(vector<vector<char>> &board) {
        if (!board.size() || !board[0].size()) return;
        int n = board.size(), m = board[0].size();

        // 让边界的o的st数组为true
        memset(st, 0, sizeof st); // 使用多次bfs，所以memset要写在题目函数中
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && board[i][j] == 'O') bfs(i, j, board, 'O');
            }
        }


        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) continue;
                if (board[i][j] == 'X' || st[i][j]) continue;
                bfs(i, j, board, 'X');
            }
        }

        return;

    }
};
class Solution {
public:
    static const int N = 1000;
    int n, m;
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
    bool st[N][N];

    bool exist(vector<vector<char>> &board, string word) {
        if(board.empty() || board[0].empty()) return false;

        n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                st[i][j] = true; // 把起点设为访问过的点
                if(board[i][j] == word[0] && dfs(board, i, j, word, 0)) return true;
                st[i][j] = false;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> &board, int sx, int sy, string &word, int u) {
        if (u == word.size() - 1) return true;

        for (int i = 0; i < 4; i ++) {
            int a = sx + dx[i], b = sy + dy[i];
            // 3个if用来剪枝,类似n皇后的if条件
            if (a < 0 || a >= n || b < 0 || b >= m) continue;
            if (st[a][b] == true) continue;
            if (board[a][b] != word[u + 1]) continue;

            st[a][b] = true;
            if (dfs(board, a, b, word, u + 1)) return true; // 只要有一个是true就会一直返回true
            st[a][b] = false;  // 恢复现场，不影响其他分支
        }

        return false;
    }

};


0x  12      34
    高字节   低字节

    低地址   高地址  大端模式
    高地址   低地址  小端模式

void IsBigEndian() { // 原理：联合体union的存放顺序是所有成员都从低地址开始存放，而且所有成员共享存储空间
    union temp {
        short a; // 2个字节
        char b;
    } temp;

    temp.a = 0x1234;
    if( temp.b == 0x12 ) { // 低字节存的是数据的高字节数据
        cout << "大端模式" << endl;
    } else {
        cout << "小端模式" << endl;
    }
}
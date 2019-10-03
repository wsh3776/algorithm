// 别人代码 我还差的远呢
class Solution {
public:
    unordered_map<long long, int> g;
    bool robot(string command, vector<vector<int>> &obstacles, int x, int y) {
        for (int i = 0; i < obstacles.size(); i++) {
            int a = obstacles[i][0], b = obstacles[i][1];
            g[a * 1e9 + b] = 1;
        }
        int i = 0, n = command.size();
        int a = 0, b = 0;
        while (1) {
            if (a == x && b == y) {
                return true;
            }
            if(a > x && b > y)return false;
            if (g.count(a * 1e9 + b)) {
                return false;
            }
            if (command[i % n] == 'U') {
                b++;
            } else if (command[i % n] == 'R') {
                a++;
            }
            i++;
        }
    }
};

//
class Solution {
public:
    int solve(vector<pair<int, int>> &pos, int dx, int dy, int x, int y) {
        for (int i = 0; i < pos.size(); i++) {
            int detax = x - pos[i].first;
            int detay = y - pos[i].second;
            if (detax % dx == 0 && detay % dy == 0 && detax / dx == detay / dy) {
                return i + (detax / dx) * int(pos.size());
            }
        }
        return -1;
    }
    bool robot(string command, vector<vector<int>> &obstacles, int x, int y) {
        vector<pair<int, int>> pos;
        pos.push_back({ 0, 0 });
        int dx = 0, dy = 0;
        for (int i = 0; i < command.size(); i++) {
            if (command[i] == 'U') dy++;
            else dx++;
            pos.push_back({ dx, dy });
        }
        //计算x,y是否再循环路劲中，输出第几个位置
        int numxy = -1;
        numxy = solve(pos, dx, dy, x, y);
        if (numxy == -1) return false;
        for (int i = 0; i < obstacles.size(); i++) {
            int numob = solve(pos, dx, dy, obstacles[i][0], obstacles[i][1]);
            if (numob >= 0 && numob <= numxy) {
                return false;
            }
        }
        return true;
    }
};



class Solution {
public:
    bool robot(string command, vector<vector<int>> &obstacles, int x, int y) {
        int ns = command.size();
        int u = 0, r = 0;
        for (int i = 0; i < ns; i ++) {
            if (command[i] == 'U') u++;
            else r++;
        }

        map <vector<int>, int> mp;
        int nx = 0, ny = 0;
        for (int i = 0; i < ns; i ++) {
            if (command[i] == 'u') nx ++;
            else ny ++;
            mp[ {nx, ny}]++;
        }

        int n = obstacles.size();
        for (int i = 0; i < n; i ++) {
            int a = obstacles[i][0], b = obstacles[i][1];
            if (a / u != b / r) continue;
            a = a % u;
            b = b % r;
            if (mp.count({a, b}) return false;
        }

    if (x / u != y / r) return false;

        x = x % u, y = y % r;
        if (mp.count({x, y}) return true;
                return false;
    }
};
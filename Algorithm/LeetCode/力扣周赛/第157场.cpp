/*
	2019年10月6日 星期日 
	AC: 1/4
	第一题看起来很难，但看别人2分钟就做出来了，仔细想了下不难
	第二题跟最长公共上升子序列有点像，但超时了，因为n = 100010;
	第三题是个dfs，我记不得怎么写了
	第四题应该也是个搜索，但我不会
	yxc说的对，dp是重点，到哪都有dp
*/

/// 5213. 玩筹码 Easy
class Solution {
public:
    int minCostToMoveChips(vector<int> &chips) {
        int n = chips.size();
        int odd = 0, even = 0;

        for (int i = 0; i < n; i ++) {
            if (chips[i] & 1) odd ++;
            else even ++;
        }

        return min(odd, even);
    }
};


///? 5214. 最长定差子序列 Medium
/*
	最长上升子序列朴素做法超时 n = 10^5  现在慢慢明白算法基础课的重要性，哪都用的到
*/
class Solution {
public:
    int longestSubsequence(vector<int> &arr, int difference) {
        int n = arr.size();
        int f[100100];
        for (int i = 0; i < n; i ++) {
            f[i] = 1;
            for (int j = 0; j < i; j ++) {
                if (arr[i] - arr[j] == difference) {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
        }

        int res = 0;
        for (int i = 0; i < n; i ++) {
            res = max(res, f[i]);
        }

        return res;
    }
};


///* 5214. 最长定差子序列 Medium
/*
	简单dp， dp[v]表示以v结尾的同时以difference为公差的最长定差子序列
*/
class Solution {
public:
    map<int, int> dp;
    int longestSubsequence(vector<int>& arr, int difference) {
        dp.clear();

        int ans=0;
        for (auto v: arr){
            int nv=max(dp[v], dp[v-difference]+1);
            ans=max(ans, nv);
            dp[v]=nv;
        }
        
        return ans;
    }
};







///? 5215. 黄金矿工 Medium
typedef pair<int, int> PII;
int d[110][110];
int bfs(int a, int b, vector<vector<int>> &g ) {
    int n = g.size(), m = g[0].size();
    queue<PII> q;
    memset(d, -1, sizeof d);
    d[a][b] = g[a][b];                            //d[x][y] != -1 表示该点被搜索过了
    q.push({a, b});
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    int x = 0, y = 0;
    while (q.size()) {
        auto t = q.front();
        q.pop();


        for (int i = 0; i < 4; i ++ ) {
            x = t.first + dx[i], y = t.second + dy[i];

            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] != 0 && d[x][y] == -1) {
                d[x][y] = d[t.first][t.second] + g[x][y];
                q.push({x, y});
            }
            if (x >= 0 && x < n && y >= 0 && y < m) x = t.first, y = t.second;
        }
    }

    int res = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            res = max(res, d[i][j]);
        }

    }
    return res;
}

class Solution {
public:
    int getMaximumGold(vector<vector<int>> &g) {
        int n = g.size(), m = g[0].size();

        int res = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (g[i][j] != 0)
                    res = max(res, bfs(i, j, g));
            }
        }


        return res;
    }
};

///* 
int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};

class Solution {
public:
    int ans=0;
    int gold[20][20], n, m;
    
    
    void dfs(int x, int y, int cur){
        int rev=gold[x][y]; gold[x][y]=0;
        cur+=rev; ans=max(ans, cur);
        
        for (int k=0; k<4; k++){
            int tx=x+dx[k], ty=y+dy[k];
            if (0<=tx && tx<n && 0<=ty && ty<m && gold[tx][ty]>0) dfs(tx, ty, cur);
        }
        
        gold[x][y]=rev;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        for (int i=0; i<n; i++) for (int j=0; j<m; j++) gold[i][j]=grid[i][j];
        
        ans=0;
        for (int i=0; i<n; i++) for (int j=0; j<m; j++) if (gold[i][j]>0) dfs(i, j, 0);
        return ans;
    }
};

/// 5216. 统计元音字母序列的数目 Hard
class Solution {
public:
    int countVowelPermutation(int n) {

    }
};


///* 5216
const long long MOD=1e9+7;
// a, e, i, o, u
// 0, 1, 2, 3, 4
class Solution {
public:
    long long dp[5], f[5];
    int countVowelPermutation(int n) {
        --n; for (int i=0; i<5; i++) dp[i]=1;
        for (int _=0; _<n; ++_){
            memset(f, 0, sizeof(f));
            f[0]=(dp[1]+dp[2]+dp[4])%MOD;
            f[1]=(dp[0]+dp[2])%MOD;
            f[2]=(dp[1]+dp[3])%MOD;
            f[3]=(dp[2])%MOD;
            f[4]=(dp[2]+dp[3])%MOD;
            for (int i=0; i<5; i++) dp[i]=f[i];
        }
        long long ans=0;
        for (int i=0; i<5; i++) ans=(ans+dp[i])%MOD;
        return ans;
    }
};
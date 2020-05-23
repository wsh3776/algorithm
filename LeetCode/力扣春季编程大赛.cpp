// 2020.04.18 力扣春季编程大赛

// 2 ？？unordered_map为什么不行
class Solution {
public:
    // f[i][t] 表示经过t轮，从0传到i的方案数；初始化f[0][0] = 1;其余f[i][0] = 0
    // [j, i]在relation中，则累加当前方案数
    
    bool check(vector<vector<int>>& relation, int a, int b) {
        for (int i = 0; i < relation.size(); i ++) {
            if (relation[i][0] == a && relation[i][1] == b) return true;
        }
        return false;
    }
    
    int numWays(int n, vector<vector<int>>& relation, int k) {
       
        int f[100][100];
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        
        for (int t = 1; t <= k; t ++) {
            for (int i = 0; i < n; i ++) {
                for (int j = 0; j < n; j ++) {
                    if (j == i) continue;
                    if (check(relation, j, i)) f[i][t] += f[j][t - 1];
                }
            }
        }
        
        return f[n - 1][k];
    }
};

// 3.暴力
class Solution {
public:
    vector<int> getTriggerTime(vector<vector<int>> &increase, vector<vector<int>> &requirements) {
        vector<vector<int>> total(increase);
        for (int i = 1; i < increase.size(); i++) {
            total[i][0] = total[i - 1][0] + increase[i][0];
            total[i][1] = total[i - 1][1] + increase[i][1];
            total[i][2] = total[i - 1][2] + increase[i][2];
        }

		int n = requirements.size();
		vector <int> res(n, -1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < total.size(); j++) {
                if (requirements[i][0] == 0 && requirements[i][1] == 0 && requirements[i][2] == 0) {
                    res[i] = 0;
                    break;
                }
                if (total[j][0] >= requirements[i][0] && total[j][1] >= requirements[i][1] &&
                    total[j][2] >= requirements[i][2]) {
                    res[i] = j + 1;
                    break;
                }
            }
        }

		return res;
    }
};

// 3.二分 看了别人的答案，原来可以直接用 lower_bound函数
class Solution {
public:
    // 先把暴力写出来，然后再想办法优化（二分）
    // 如：requirements[i] = [12,11,16]，三次二分，找到他们的最大值
    
    
    // 这里必须传引用，不然会超时
    int getPosition(vector<vector<int>> &total, vector<vector<int>> &requirements, int i, int k) { 
        int n = requirements.size(), m = total.size();
        int l = 0, r = m - 1;
        
        while (l < r) {
            int mid = (l + r) >> 1;
            if (total[mid][k] >= requirements[i][k]) r = mid;
            else l = mid + 1;
        }
        // cout << total[r][k] << "&" << r <<endl;
        if (total[r][k] < requirements[i][k]) {
            return -1;
        }
        
        return r + 1;
    }
    
    vector<int> getTriggerTime(vector<vector<int>> &increase, vector<vector<int>> &requirements) {
        vector<vector<int>> total(increase);
        for (int i = 1; i < increase.size(); i++) {
            total[i][0] = total[i - 1][0] + increase[i][0];
            total[i][1] = total[i - 1][1] + increase[i][1];
            total[i][2] = total[i - 1][2] + increase[i][2];
            
        }

		int n = requirements.size(), m = total.size();
		vector <int> res(n, 0);
        for (int i = 0; i < n; i++) {
             if (requirements[i][0] == 0 && requirements[i][1] == 0 && requirements[i][2] == 0) {
                    res[i] = 0;
                    continue;
                }
            
            int tmp[3];
            for (int t = 0; t < 3; t ++) {
                int hk = getPosition(total, requirements, i, t); // 一开始这里传参写成了increase
                // cout << t << "," << hk << endl;
                if (hk == -1) {
                    res[i] = -1;
                    break;
                } 
                //cout << hk << "--" << i << endl;
                tmp[t] = hk;
            }
            
            if (res[i] != -1) {
                res[i] = max(tmp[0], max(tmp[1],tmp[2]));
            }
            
        }

		return res;
    }
};

// 4. bfs最后没做出来
class Solution {
public:
    // 遍历一次，找到最能跳出的最靠前的点
    
    // [2, 5, 1, 1, 1, 1]
    //  t
    int n;
    static const int N = 1e6 + 7;
    int st[N], q[N];
    long long dt[N];
    
    int bfs(vector<int> jump, int k) {
        int hh = 0, tt = 0;
        q[tt ++] = k;
        st[k] = 1;
        
        while (hh < tt) {
            int d = q[hh ++];
            
            if (d + jump[d] >= n) {dt[n] = min(dt[n], dt[d] + 1);}
            
            if (!st[d + jump[d]]) {
            dt[d+jump[d]] = dt[d] + 1;
            q[tt ++] = d + jump[d];
            st[d + jump[d]] = 1;
            }
            
            for (int i = 0; i < d; i ++) {
                if (!st[i]) {
                    dt[i] = dt[d] + 1;
                    q[tt ++] = i;
                    st[i] = 1;
                }
            }   
        }
        
        return dt[n];
    }
    
    int minJump(vector<int>& jump) {
        n = jump.size();
        memset(st, 0, sizeof(st));
        memset(dt, 0, sizeof(dt));
        dt[n] = 0x3f3f3f3f;
        
        return bfs(jump, 0);
    
    }
};

// duyu
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5e4 + 7;
int a[N];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}

	sort(a, a + n);

	int q;
	cin >> q;
	while (q --) {
		int d;
		cin >> d;
		int res = 0;
		for (int i = 0; i < d; i ++) {
			res += a[i] * ((d - 1 - i) / m + 1);
		}
		cout << res << endl;
	}

	return 0;
}
class Solution {
public:
    int pro(int t) {
        int num = 1;
        for (int i = 1; i <= t; i ++) {
            num *= i;
        }
        return num;
    }

    int func(int n) {
        if (n == 1) return 0;
        if (n == 2) return 1;
        return (n - 1) * func(n - 1) * func(n - 2);
    }

    int solve(int n) {
        int cnt = 0;
        for (int k = 1; k <= n; k ++) {
            cnt += k * func(n - k) / pro(n - k);
        }

        return cnt;
    }

    int expectNumber(vector<int>& scores) {
        sort(scores.begin(), scores.end());
        
        int n = scores.size();
        long long res = 0;
        
        for(int i = 0, j = 0; i < n;) {
            while(j < n && s[j] == s[i]) j ++;

            res += solve(j - i); 
            
            i = j; 
        }

        return res;
    }
};








// 2：二分前几天录个视频，现在在做就会了
class Solution {
public:
    // 二分答案T，对于每一段，如果和减去最大值，则还可以加进来，天数--
    
    bool check(int mid, vector<int>& time, int m) {
        int n = time.size();
        int rmax = -1, sum = 0;
        
        for (int i = 0; i < n; i ++) {
            rmax = max(rmax, time[i]);
            sum += time[i]; // 清零
            //cout << sum << " " << rmax << " " << mid << endl;
            if (sum - rmax > mid) {
                sum = 0;
                rmax = -1;     
                m --;
                i --;
                //cout << "Here: " << i << endl;
            }
            
            if (m == 0) break;
        }
        
        return m == 0;
    }
    
    int minTime(vector<int>& time, int m) {
        int l = 0, r = 1e9; 
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid, time, m)) l = mid + 1;
            else r = mid;
        }
        
        return l;
    }
};
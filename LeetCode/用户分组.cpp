/**
 *    @Author: Wilson79
 *    @Datetime: 2019年12月8日 星期日 10:35:13
 *    @Filename: 用户分组.cpp
 */

// 结构体排序即可

typedef pair<int, int> PII ;


class Solution {
public:
    static bool cmp(PII A, PII B) {
        if (A.first < B.first) return true;
        else if (A.first == B.first && A.second < B.second) return true;
        return false;
    }

    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        PII a[n];
        for (int i = 0 ; i < n; i ++) {
            a[i].first = groupSizes[i];
            a[i].second = i;
        }

        sort(a, a + n, cmp);

        vector<vector<int>> res;
        int t = 0;
        for (int i = 0, j = i; i < n; ) {
            vector<int> tmp;
            int cnt = 0;
            while(j < n && a[j].first == a[i].first && cnt < a[i].first) {
                tmp.push_back(a[j].second);
                t ++;
                j ++;
                cnt ++;
            }
            i = j;
            res.push_back(tmp);
        }
        
        return res;
    }
};
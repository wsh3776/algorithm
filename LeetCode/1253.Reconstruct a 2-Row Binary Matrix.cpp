class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int> &colsum) {
        // optional position +　greedy
        vector<vector<int>> res(2);

        int cnt1 = 0, cnt2 = 0, cnt0 = 0;
        for (auto t : colsum) {
            if (t == 1) cnt1 ++;
            if (t == 2) cnt2 ++;
            if (t == 0) cnt0 ++;
        }

        int ftone = upper - cnt2, sdone = lower - cnt2;
        // empty
        if (ftone + sdone != cnt1 || sdone < 0 || ftone < 0) 
            return {};

        int k = 0;
        for (auto t : colsum) {
            if (t == 2) res[0].push_back(1), res[1].push_back(1);
            if (t == 0) res[0].push_back(0), res[1].push_back(0);
            // fill one
            if (t == 1 && k < ftone) {
                res[0].push_back(1), res[1].push_back(0);
                k ++;
            }
            else if (t == 1 && k >= ftone) {
                res[0].push_back(0), res[1].push_back(1);
                k ++;
            }
        }

        return res;
    }
};
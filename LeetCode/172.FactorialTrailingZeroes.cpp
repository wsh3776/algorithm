class Solution {
public:
    int trailingZeroes(int n) {
        // the count 5 is less than 2        
        // 31/5 + 6/5 + 1/5 = 7
        int cnt = 0;
        while(n) {
            cnt += n / 5;
            n /= 5;
        }
        return cnt;
    }
};

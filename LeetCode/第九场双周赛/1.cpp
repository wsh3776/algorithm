// 最多能买到苹果的数量	
class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int sum = 0, res = 0;
        for (int i = 0; i < arr.size(); i ++) {
        	sum += arr[i];
        	if (sum <= 5000) res ++;
        	else break;
        }

        return res;
    }
};
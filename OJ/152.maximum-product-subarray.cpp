#include <iostream>
#include <vector>

using namespace std;

int maxProduct(vector<int> &nums) {
    int i;
    int ans = nums[0];
    int imax[nums.size()];
    imax[0] = nums[0];
    int imin[nums.size()];
    imin[0] = nums[0];
    for (i = 1; i < nums.size(); i++) {
        imax[i] = max(nums[i], max(imax[i - 1] * nums[i], imin[i - 1] * nums[i]));
        imin[i] = min(nums[i], min(imax[i - 1] * nums[i], imin[i - 1] * nums[i]));
        // printf("imax=%d ", imax[i]);
        // printf("imin=%d ", imin[i]);
        ans = max(imax[i], ans);
        // printf("ans=%d ", ans);
        // printf("\n");
    }
    return ans;
}

int main() {
    // 5
    // 1 2 3 2 2
    vector<int> arr;
    int n, d;
    cin >> n;
    while (n-- && cin >> d) {
        arr.push_back(d);
    }

    cout << maxProduct(arr) << endl;

    return 0;
}
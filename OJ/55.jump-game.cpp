#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int> &nums) {
    // 遍历数组，更新最大可以到达的距离，如果i > maxPosition，则返回false
    int n = nums.size(), maxPosition = 0;
    for (int i = 0; i < n; i++) {
        if (i > maxPosition) return false;
        maxPosition = max(maxPosition, i + nums[i]);
    }
    return true;
}

int main() {
    int n, d;
    cin >> n;
    vector<int> nums;
    while (n-- && cin >> d)
        nums.push_back(d);

    cout << canJump(nums) << endl;

    return 0;
}
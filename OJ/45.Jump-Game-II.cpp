#include <iostream>
#include <vector>

using namespace std;

int jump(vector<int> &nums) {
    // 每次更新最大值，然后如果i  == end，则steps ++，如果end >= size - 1，则退出循环
    int n = nums.size();
    int end = 0;
    int steps = 0;
    int maxPosition = 0;

    if (n <= 1) return steps;
    for (int i = 0; i < n; i++) {
        maxPosition = max(maxPosition, i + nums[i]);
        if (i == end) {
            steps++;
            end = maxPosition;
            if (end >= n - 1) break;
        }
    }
    return steps;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    int d;
    vector<int> nums;
    while (cin >> d)
        nums.push_back(d);

    cout << jump(nums) << endl;

    return 0;
}
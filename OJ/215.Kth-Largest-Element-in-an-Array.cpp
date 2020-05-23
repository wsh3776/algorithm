#include <iostream>
#include <queue>

using namespace std;

int findKthLargest(vector<int> &nums, int k) {
    // 思路：使用小根堆，每当堆中有 k + 1 个元素时，那栈顶一定不可能是第 k 大的元素
    // 遍历这个nums数组，最后堆中会剩下 k 个元素，此时栈顶元素就是nums数组中第 k 大的数

    // 时间复杂度：O(nlogk)
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < nums.size(); i++) {
        q.push(nums[i]);
        if (q.size() > k) q.pop();
    }
    return q.top();
}

int main() {
    int n, d, k;
    cin >> n >> k;
    vector<int> nums;
    while (n-- && cin >> d) {
        nums.push_back(d);
    }

    cout << findKthLargest(nums, k) << endl;

    return 0;
}
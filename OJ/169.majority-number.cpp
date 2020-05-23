#include <iostream>
#include <vector>

using namespace std;

// Time: O(n)  Space: O(1)
int majorityElement(vector<int> &nums) {
    int findNum = 0, cnt = 0;
    // 1 1 2 3 1 4 1 1
    for (int i = 0; i < nums.size(); i++) {
        if (cnt == 0) {
            findNum = nums[i];
            cnt++;
        } else {
            if (findNum == nums[i])
                cnt++;
            else
                cnt--;
        }
    }
    return findNum;
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

    cout << majorityElement(arr) << endl;

    return 0;
}
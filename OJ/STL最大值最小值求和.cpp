/*
 * @Date: 2020-05-09 22:31:05
 * @FilePath: /Wilson79/Algorithm/OJ/STL最大值最小值求和.cpp
 * @LastEditors: cs_shwei@163.com
 * @LastEditTime: 2020-05-09 22:31:05
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric> 

using namespace std;

int main() {
    int a[] = {1, 2, 3, 4, 5};
    vector<int> v({1, 2, 3, 4, 5});

    // 普通数组
    int minValue = *min_element(a, a + 5); 
    int maxValue = *max_element(a, a + 5); 
    int sumValue = accumulate(a, a + 5, 0);

    // Vector数组
    int minValue2 = *min_element(v.begin(), v.end());
    int maxValue2 = *max_element(v.begin(), v.end());
    int sumValue2 = accumulate(v.begin(), v.end(), 0);

    cout << minValue << endl;
    cout << maxValue << endl;
    cout << sumValue << endl << endl;

    cout << minValue2 << endl;
    cout << maxValue2 << endl;
    cout << sumValue2 << endl << endl;
    return 0;
}

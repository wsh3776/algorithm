/*
 * @Date: 2020-05-16 18:39:16
 * @FilePath: /Wilson79/Algorithm/OJ/欧拉函数.cpp
 * @LastEditors: cs_shwei@163.com
 * @LastEditTime: 2020-05-16 23:04:45
 */
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;

        int res = a;
        // 欧拉函数核心：分解质因数
        for (int i = 2; i <= a / i; i++) {
            if (a % i == 0) {            // 如: i = 2
                res = res / i * (i - 1); // 先除以i，可避免出现小数
                while (a % i == 0) {     // 把因子i除干净，保证下个因子一定是质因子
                    a = a / i;
                }
            }
        }

        if (a > 1) res = res / a * (a - 1); // n 中最多只包含一个大于sqrt n 的质因子
        cout << res << endl;
    }

    return 0;
}
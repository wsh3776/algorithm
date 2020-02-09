/**
 *    @Author: Wilson79
 *    @Datetime: 2020年1月10日 星期五 20:55:01
 *    @Filename: 131.直方图中最大的矩形（单调栈）.cpp
 */

#include <iostream>

using namespace std;

const int N = 1e5 + 7;

typedef long long LL;

int q[N], nums[N], Left[N], Right[N]; // (Left, Right数组存下标)
int n, hh = 0, tt = 0;

int main() {
    while (cin >> n) {
        
        if (n == 0) break;
        for (int i = 0; i < n; i ++) {
            cin >> nums[i];
        }

        // 单调栈
        // 找到左边第一个比当前位置小的元素的下标，并存到Left数组中
        hh = 0, tt = 0; // 多组测试数据
        Left[0] = -1; // 别忘记边界值
        for (int i = 0; i < n; i ++) {
            while(hh < tt && nums[q[tt - 1]] >= nums[i]) tt --;
            if (hh < tt) Left[i] = q[tt - 1];
            else Left[i] = -1;

            q[tt ++] = i;
        }

        // 同理处理右半部分
        hh = 0, tt = 0;
        Right[n - 1] = n;
        for (int i = n - 1; i >= 0; i --) {
            while(hh < tt && nums[q[tt - 1]] >= nums[i]) tt --;
            if (hh < tt) Right[i] = q[tt - 1];
            else Right[i] = n;

            q[tt ++] = i;
        }

        LL mx = 0;
        for (int i = 0; i < n; i ++) {
            mx = max(mx, nums[i] * 1ll * (1 + i - Left[i] - 1 + Right[i] - i - 1)); // 统计每个位置最大值
        }
        
        cout << mx << endl;
    }

    return 0;
}


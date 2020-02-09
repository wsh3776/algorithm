/**
 *    @Author: Wilson79
 *    @Datetime: 2020年1月8日 星期三 17:01:00
 *    @Filename: 可旋栈.cpp
 */

#include <iostream>

using namespace std;

const int N = 1000000;

// 数组模拟栈（队列）
int hh, tt;
int stk[N];

int main() {
    #ifdef ONLINE_JUDGE
    #else
    freopen("in.txt", "r", stdin);
    #endif

    int n = 0;
    cin >> n;
    hh = 300007, tt = 300007;
    int flag = 1;
    while(n --) {
        int a, x;
        cin >> a;


        if (a == 1) {
            // x入栈
            cin >> x;
            stk[tt] = x;
            if(flag > 0) tt ++;
            else tt --;
        }

        if (a == 2) {
            // 弹出栈顶元素
            if (flag > 0) tt --;
            else tt ++;
        }
        
        if (a == 3) {
            // cout << "Here: " << hh << " " << tt << endl; 
            // 翻转栈
            if (flag > 0) {
                if (hh < tt) {
                    int tmp = tt - 1;
                    tt = hh - 1; // 原来我写了tt = hh--; 这个bug很难发现
                    hh = tmp;
                }
            }

            if (flag < 0) {
                if (hh > tt) {
                    int tmp = hh + 1;
                    hh = tt + 1;
                    tt = tmp;
                }
            }

            flag = flag * (-1); // -1表示倒着的
            // cout << "Here: " << hh << " " << tt << endl;
        }

        // 输出栈顶元素
        if ((flag > 0 && hh >= tt) || (flag < 0 && hh <= tt)) cout << -1 << endl;
        else if  ((flag > 0 && hh < tt) || (flag < 0 && hh > tt)) {
            if (flag > 0) cout << stk[tt - 1] << endl;
            else cout << stk[tt + 1] << endl;
        }
    }

    return 0;
}

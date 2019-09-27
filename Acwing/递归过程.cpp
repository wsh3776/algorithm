#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e8;
//12 / 8 = 1
//12 % 8 = 4
// 1 / 8 = 0   end
// 1 % 8 = 1

// 进制转化用vector去存会比较方便
vector <int> v, vec;
int res = 0;

// 十进制转为k进制    利用递归
void BeforeRecursive(int n) {
    if (n == 0)
        return;
    v.push_back(n % 2); // 这行在前在后有区别  每次先做这个再往下走
    BeforeRecursive(n / 2);
}

void AfterRecursive(int n) {
    if (n == 0)
        return;
    AfterRecursive(n / 2);
    vec.push_back(n % 2); // 这行在前在后有区别  先走到底了，再回来做
}


int main(void) {
    int n; // 6
    scanf("%d", &n);

    BeforeRecursive(n);

    AfterRecursive(n);

    cout << "执行语句在递归语句前：" ; // 011
    for (auto x : v)
        cout << x;
    cout << endl;

    cout << "执行语句在递归语句后：" ; // 110
    for (auto x : vec)
        cout << x;
    cout << endl;

    return 0;
}
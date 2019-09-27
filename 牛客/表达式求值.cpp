// 1+1*3+4

// 8
#include <bits/stdc++.h>
using namespace std;
<<<<<<< HEAD

=======
>>>>>>> update9.7
int main(void)
{
    string s;
    long len, t = 1, a = 0, ans = 0;
    cin >> s;
    len = s.size();
    for (int i = 0; i < len; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            a = a * 10 + s[i] - '0';
        else if (s[i] == '+')
        {
            a = (a * t) % 10000;
            ans = (ans + a) % 10000;
            a = 0;
            t = 1;
        }
        else if (s[i] == '*')
        {
            t = (a * t) % 10000;
            a = 0;
        }
    }
    a = (a * t) % 10000;
    ans = (ans + a) % 10000;
    cout << ans << endl;
<<<<<<< HEAD

=======
>>>>>>> update9.7
    return 0;
}
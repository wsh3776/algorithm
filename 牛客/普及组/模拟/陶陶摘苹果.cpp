#include <iostream>

using namespace std;

int v[10];

int main()
{
    for (int i = 0; i < 10; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; if)
        int h;
    cin >> h;
    h += 30;

    int res = 0;
    for (auto x : v)
    {
        if (h >= x)
            res++;
    }

    cout << res << endl;
    return 0;
}
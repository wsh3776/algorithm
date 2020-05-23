// https://acm.ecnu.edu.cn/problem/2946/
#include <iostream>

using namespace std;

void getDivides(int n) {
    for (int i = 2; i <= n / i; i ++) {
        if (n % i == 0) {
            int s = 0;
            while (n % i == 0) {
                n /= i;
                s ++;
            }
            printf("(%d,%d)", i , s);
        }
    }

    if (n > 1) printf("(%d,%d)", n , 1);
    puts("");
}

int main() {
    int T;
    cin >> T;

    while (T --) {
        int n;
        cin >> n;
        getDivides(n);
    }
    
    return 0;
}

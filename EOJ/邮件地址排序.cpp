#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<string, string> PSS;
const int N = 1e6;

bool cmp(PSS A, PSS B) {
    if (A.second < B.second)
        return true;
    else if (A.second)
}


PSS mail[N];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        scanf("%s@%s", mail[i].first, mail[i].second));
    }

    sort(mail.begin(), mail.end(), cmp);

    return 0;
}
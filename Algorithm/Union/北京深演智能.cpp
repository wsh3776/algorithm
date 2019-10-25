#include <iostream>
#include <map>
using namespace std;

int main(){
  map <char, int> hash;
  string s, res = "";
  cin >> s;
  
  int n = s.size();
  for (int i = 0; i < n; i ++) {
    if (++hash[s[i]] == 1) {
      res += s[i];
    }
  }
  
  cout << res << endl;
  return 0; 
}

// 回文串
#include <iostream>
#include <algorithm>

using namespace std;

bool isAngram(string s) {
  int n = s.size();
  int i = 0, j = n - 1;
  for ( ; i < j; ) {
    if (s[i] == s[j]) {
      i ++, j --;
    }
    else {
      return false;
    }
  }
    return true; 
 
}

int main(){
  string s, res = "";
  cin >> s;
  int n = s.size();
  for (int i = 0; i < n; i ++) {
    string tmp = s.substr(n - 1 - i, i + 1);
    reverse(tmp.begin(), tmp.end());
    res = tmp + s;
    if (isAngram(res)) {
      cout << res << endl;
      break;
    }
  }
  
  
  return 0; 
}


// 我好像忘记它要我求的是连续的数组了，后悔啊
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int a, n;
  vector <int> v;
  while (cin >> a) {
    v.push_back(a);
  }
  
  n = v.size();
  vector <int> Max(n, 0);
  vector <int> Min(n, 0);
  Max[0] = v[0], Min[0] = v[0];
  
  int res = 0;
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < i; j ++) {
    	Max[i] = max(Max[j] * v[i], max(Min[j] * v[i], v[i]));
        Min[i] = min(Max[j] * v[i], min(Min[j] * v[i], v[i]));
    }
    res = max(Max[i], res);
  }
  
  cout << res << endl;
  
  return 0;
}


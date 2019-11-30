/*
    Author: Wilson79
    Filename: test.cpp
    Filepath: /Users/macos/Documents/Wilson79/Algorithm/Algorithm/Union/test.cpp  
*/
/*
    Author: Wilson79
    Filename: test.cpp
    Filepath: /Users/macos/Documents/Wilson79/Algorithm/Algorithm/Union/test.cpp  
*/

#include <iostream>

using namespace std;

typedef struct Node {
    int val;
    struct Node *next;
}Node;

Node * a = 0;

int main() {
    #ifdef ONLINE_JUDGE
    #else
    freopen("in.txt","r",stdin);
    #endif

    mb
    {3:int} solve(int n) {
        

void in(/* ElemType */) {
    fsd
}
    }
int sf(int a, itn b) {
    sfi
sf sdf(int n) {
    for
}
}
    return 0;
}
#include <iostream>

using namespace std;

#include <iostream>

using namespace std;

int main() {
    #ifdef ONLINE_JUDGE
    #else
    freopen("in.txt","r",stdin);
    #endif

    sf

    return 0;
}

int main() {
    #ifdef ONLINE_JUDGE
    #else
    freopen("in.txt","r",stdin);
    #endif

    sf

    return 0;
}


#include <fs>
#include <sfd>
    for (int i = 0; i < n; i ++) {
        Author: Wilson79
        Filename: test.cpp
        Filepath: /Users/macos/Documents/Wilson79/Algorithm/Algorithm/Union/test.cpp  
    }
    #endif
    定义函数latex 上下标等
    test.cpp
    test.cpp   用户文件名
Author: Wilson79
Filename: test.cpp
Filepath: /Users/macos/Documents/Wilson79/Algorithm/Algorithm/Union/test.cpp  
"%s" % datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")


    
    

 latex模版

    签名 日期

    latex模版

    签名 日期


    latex模版

    签名 日期


fsd
#include <
>
if (sdf) {
    if (/* condition */) {
        /* code */
    }
    fsd
    #ifdef ONLINE_JUDGE
    #else
    freopen("in.txt","r",stdin);
    #endif
    
    
    
    for (int i = 0; i < sfd; i++) {
        sf
        for (int i = 0; i < n; i++) {
            sf
        }
        #ifdef ONLINE_JUDGE
        #else
        freopen("in.txt","r",stdin);
        #endif
        
        
        
        fre
        cout << "sf" << endl;
        cout << "" << endl;
        cout << "sdf" << endl;
    }cout << "sf
    cout2" << endl;
    cout << "" << endl;

}
for (int i = 0; i < fs; i++) {
    fsd
}
sf.begin(), sf.end();
bd.begin(), bd.end()
#include "test.h"
      for (int i = 0; i < count; ++i)
    {
        /* code */
    }   for (int i = 0; i < n; i++) {
        
    }
#include <fs>
#include <fs>
struct sf {
    #ifdef ONLINE_JUDGE
    #else
    freopen("in.txt","r",stdin);
    #endif
#include <experimental/set>
#include <sf>

#ifdef ONLINE_JUDGE
#else
freopen("in.txt","r",stdin);
#endif
#in
#include <sdf>
#include <sdf>
#include <sdf>
#include <s>
#include <sdf>
};
    for (int j = 0; j < sf; j++) {
        sdf
    }
    for (int i = 0; i < sfd; i++) {
        fasd
        for (int i = 0; i < n; ++i) {
            /* code */
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    for (int i = 0; i < n; i++) {
                        
                    }
                }
            }

            for (int i = 0; i < count; ++i) {
                for (int j = 0; j < m; j++) {
                    sfd
                    for (int i = 0; i < count; i++) {
                        for (int i = 0; i < count; i++) {
                            for (int i = 0; i < count; i++) {
                                for (int i = 0; i < count; i++) {
                                        for (int i = 0; i < count; i++) {
                                            
                                        }
                                    }    
                            }
                        }
                    }
                }
            }
        }

        sff

    for (int j = 0; j < sf; j++) {
        sff
    }
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
        } else {
            return false;
        }
    }
    for (int j = 0; j < sf; ++j) {
        
    }
            for (int i = 0; i < count; ++i)
    {
        /* code *f
    }
            for (int saf = 0; saf < sdf; ++saf)
    {
        /* code */
    }
    return true;

}

int main() {
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


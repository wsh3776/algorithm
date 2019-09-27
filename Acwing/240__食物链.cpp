/*
    0->1->2->0  0是根节点

    
    距离d：记录当前节点到根节点的距离
    余1：可以吃根节点
    余2：可以被根节点吃 x
    余0：与根节点是同类 y

    x吃y：x - y mod 3 为1
    x被y吃：x - y mod 3 为2
*/
#include <iostream>
#include <cstdio>
using namespace std;

const int N = 50010;

int n, m;
int p[N], d[N];

int find(int x)
{
    if (p[x] != x)
    {
        int t = find(p[x]);  // 递归语句必须写在前面，这样可以保证你先到达了根节点，然后倒过来一步步执行后面的语句
        // 因为p[a] = b, p[b] = c;你合并了三棵树，这是你再取a树中的点，find(x)它的d[p[x]]需要先更新，因为d[p[x]]还存的是x到a的距离
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

// int find(int x) {
//  if (p[x] != x) {
//      d[x] += d[p[x]];  // 这样写距离会变短，比如你Union了三棵树 d[p[x]]一直没被更新  这个问题我想了很久才搞明白，每次碰到递归就头疼
//      p[x] = find(p[x]);
//  }
//  return p[x];
// }

int main() {
    #ifdef ONLINE_JUDGE
    #else
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    
    cin >> n >> m;

    for (int i = 1; i <= n; i ++) {
        p[i] = i;
    } 

    int res = 0;
    while (m --) {
        int t, x, y;
        cin >> t >> x >> y;

        if (x > n || y > n) res ++;
        else {
            int px = find(x), py = find(y);
            if (t == 1) {  // 同类
                if (px == py && (d[x] - d[y]) % 3 != 0) res ++;
                else if (px != py) {
                    p[px] = py;
                    d[px] = d[y] - d[x];
                }
            } else { // t == 2 给出谁吃谁
                if  (px == py && (d[x] - d[y] - 1) % 3) res ++;
                else if (px != py) {
                    p[px] = py;
                    d[px] = d[y] - d[x] + 1;
                }
            }
        }   
    } 

    cout << res << endl;

    return 0;
}
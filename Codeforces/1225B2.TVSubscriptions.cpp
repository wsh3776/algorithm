#include<iostream>
using namespace std;
int b[1000000];
int main()
{
    int a[200000],t,n,k,d,i,p,q;
    while(cin>>t)
        while(t--)
        {
            cin >> n >>k>>d;
            for(i=0;i<n;i++)
            {
                cin>>a[i];
                b[a[i]]=0;
            }
            p=0;
            for(i=0;i<d;i++)
                if(b[a[i]]++==0)p++;
            q=p;
            for(i=d;i<n;i++)
            {
                if(--b[a[i-d]]==0)p--;
                if(b[a[i]]++==0)p++;
                q=min(p,q);
            }
            cout<<q<<endl;
        }
    return 0;
}

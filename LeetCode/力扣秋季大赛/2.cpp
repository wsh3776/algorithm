// 别人代码
class Solution

public:
    vector<int> fraction(vector<int> &cont)
    {
        int n = cont.size();
        if(n == 1) return {cont[0], 1};
        vector<int> top(n, 1);
        for(int i = n - 2 ; i >= 0 ; i --)
        {
            top[i] = cont[i + 1];
            cont[i] = cont[i] * cont[i + 1] + top[i + 1];
        }
        return {cont[0], top[0]};
    }
};

//
class Solution
{
public:
    long long gcd(long long x, long long y)
    {
        return y ? gcd(y, x % y) : x;
    }
    vector<int> fraction(vector<int> &cont)
    {
        long long x, y, n = cont.size(), i;
        x = cont[n - 1];
        y = 1;
        for(i = n - 2; ~i; i--)
        {
            swap(x, y);
            x += cont[i] * y;
        }
        i = gcd(x, y);
        x /= i;
        y /= i;
        vector<int> ans;
        ans.push_back(x);
        ans.push_back(y);
        return ans;
    }
};



// 分数化简，这个题不应该卡那么久的

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

class Solution
{
public:
    vector<int> fraction(vector<int> &cont)
    {
        int n = cont.size();

        int u = 1, d = 0;
        int i = n;
        while (i > 0)
        {
            int tmp1 = cont[i - 1] * u + d;
            int tmp2 = u;
            //cout << "here1: " << tmp1 << " " << tmp2 << endl;
            int g = gcd(tmp1, tmp2);
            u = tmp1 / g;
            d = tmp2 / g;
            //cout << i << endl;
            //cout << u << ":" << d << endl;
            i --;
        }

        int g = gcd(u, d);
        return {u / g, d / g};
    }


};
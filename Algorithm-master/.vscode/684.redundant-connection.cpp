/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */
class UnionFind
{
public:
    vector<int> father;
    UnionFind(int num)
    {
        for (int i = 0; i < num; i++)
        {
            father.push_back(i);
        }
    }

    int Find(int n)
    {
        if (father[n] == n)
            return n;
        father[n] = Find(father[n]);
        return father[n];
    }

    bool Union(int a, int b)
    {
        int fa = Find(a);
        int fb = Find(b);
        father[fb] = fa;
        return fa == fb; // 判断两个点是否连通
    }
};


class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();

        UnionFind UF(n);
        for (int i = 0; i < n; i++)
        {
            int x = edges[i][0], y = edges[i][1];
            // 初始化是0,1..n-1,所有下标要先减1，不然会越界
            if (UF.Union(x - 1, y - 1))
            {
                return {x, y};
            }
        }

        return {1, 1};
    }
};

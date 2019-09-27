// Find 和 Union前的返回类型容易忘记，UF.Find的UF容易忘记


class UnionFind {
public:
    vector<int> father;
    // num表示元素个数
    // 这里的UnionFind定义在这里其实是为了方便初始化并查集
    // 如UnionFind UF(n);
    UnionFind(int num) {
        for (int i = 0; i < num; i ++) {
            father.push_back(i); // 箭头指向自己
        }
    }

    // 4->3->1->1 finish
    int Find(int n) {
        // 非递归
        while(father[n] != n) {
            n = father[n];
        }
        return n;
    }

    int Find(int n) {
        // 递归
        if (father[n] == n) return n;
        return Find(father[n]);
    }

    // 不仅返回了4的最终boss，还让4和1建立了一个联系，方便下次直接找1
    int Find(int n) {
        // 递归 + 路径压缩
        if(father[n] == n) return n;
        father[n] = Find(father[n]);
        return father[n];
    }

    void Union(int a, int b) {
        int fa = Find(a); // 2的原老大是1
        int fb = Find(b); // 4的原老大是3
        father[fb] = fa;   // 让3指向1
    }
};
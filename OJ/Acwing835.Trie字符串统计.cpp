#include <iostream>

using namespace std;

class Trie {
private:
    //每个Trie节点有一个isEnd变量, 一个包含26个指针的next数组
    Trie *next[26] = {nullptr};
    int isEnd = 0;

public:
    Trie() {
    }

    // 插入单词
    void insert(const string &word) {
        Trie *root = this;
        for (const auto &ch : word) {
            char w = ch - 'a';
            if (root->next[w] == nullptr) root->next[w] = new Trie();
            root = root->next[w];
        }
        root->isEnd++;
    }

    // 查找单词
    int search(const string &word) {
        Trie *root = this;
        for (const auto &ch : word) {
            char w = ch - 'a';
            if (root->next[w] == nullptr) return false;
            root = root->next[w];
        }
        return root->isEnd;
    }
};

int main() {
    Trie trie;

    int n;
    cin >> n;
    while (n--) {
        string op, str;
        cin >> op >> str;
        if (op == "I")
            trie.insert(str);
        else
            cout << trie.search(str) << endl;
    }

    return 0;
}
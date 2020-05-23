/*
 * @Date: 2020-03-10 10:01:48
 * @FilePath: /Wilson79/Algorithm/OJ/trie树模版.cpp
 * @LastEditors: cs_shwei@163.com
 * @LastEditTime: 2020-05-07 14:15:08
 */

class Trie {
private:
    //每个Trie节点有一个isEnd变量, 一个包含26个指针的next数组
    Trie *next[26] = {nullptr}
    bool isEnd = false;

public:
    Trie() {
    }

    void insert(const string &word) { // 插入单词;
        Trie *root = this;
        for (const auto &ch : word) {
            char w = ch - 'a';
            if (root->next[w] == nullptr) root->next[w] = new Trie();
            root = root->next[w];
        }
        root->isEnd = true;
    }

    bool search(const string &word) { // 查找单词
        Trie *root = this;
        for (const auto &ch : word) {
            char w = ch - 'a';
            if (root->next[w] == nullptr) return false;
            root = root->next[w];
        }
        return root->isEnd;
    }

    bool startsWith(string prefix) { // 查找前缀
        Trie *root = this;
        for (const auto &ch : prefix) {
            char w = ch - 'a';
            if (root->next[w] == nullptr) return false;
            root = root->next[w];
        }
        return true;
    }
};

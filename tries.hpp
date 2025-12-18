#include <iostream>
#include <string>
using namespace std;

class Tries {
public:
    class TrieNode {
    public:
        bool isLeaf;
        TrieNode* children[26];
        TrieNode() {
            isLeaf = false;
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
    };

    Tries() { root = new TrieNode(); }
    void insert(const string& word);
    void print();
    bool search(const string& word);
    bool isPrefix(const string& word);

private:
    TrieNode* root;
    void print(TrieNode* node, string prefix);
};

void Tries::insert(const string& word) {
    TrieNode* node = root;
    for (char letter : word) {
        if (letter < 'a' || letter > 'z') continue;
        int idx = letter - 'a';
        if (!node->children[idx])
            node->children[idx] = new TrieNode();
        node = node->children[idx];
    }
    node->isLeaf = true;
}

void Tries::print(TrieNode* node, string prefix) {
    if (node->isLeaf)
        cout << prefix << endl;
    for (int i = 0; i < 26; i++)
        if (node->children[i])
            print(node->children[i], prefix + char('a' + i));
}

bool Tries::search(const string& word) {
    TrieNode* node = root;
    for (char letter:word) {
        if (letter < 'a' || letter > 'z') return false;
        if (node->children[letter - 'a'] == nullptr) return false;
        node = node->children[letter - 'a'];
    }
    return node->isLeaf;
}

bool Tries::isPrefix(const string& word) {
    TrieNode* node = root;
    for (char letter:word) {
        if (node->children[letter - 'a'] == nullptr) return false;
        node = node->children[letter - 'a'];
    }
    return true;
}

void Tries::print() { print(root, ""); }


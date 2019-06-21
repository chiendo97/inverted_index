#include <bits/stdc++.h> 

using namespace std;

struct Trie {
    bool isLeaf;
    vector<int> v_index;
    set<int> v_set;
    unordered_map<char, Trie*> map;
};

Trie* initializeTrie() {
    Trie* node = new Trie;
    node->isLeaf = false;

    return node;
}

void insert(Trie*& root, const char* str, int index) {
    if (root == nullptr) 
        root = initializeTrie();

    Trie* curr = root;

    while (*str) {

        if (curr->map.find(*str) == curr->map.end()) 
            curr->map[*str] = initializeTrie();

        curr = curr->map[*str];

        str++;
    }

    curr->isLeaf = true;
    curr->v_index.push_back(index);
    curr->v_set.insert(index);
}

set<int> search(Trie* root, const char* str) {

    set<int> empty_set;

    if (root == nullptr) 
        return empty_set;

    Trie* curr = root;

    while (*str) {

        curr = curr->map[*str];

        if (curr == nullptr) 
            return empty_set;

        str++;
    }

    return curr->isLeaf ? curr->v_set : empty_set; 
}

#include <bits/stdc++.h> 

using namespace std;

struct Trie {
    bool isLeaf;

    // v_set: what documents has this word
    set<int> v_set;
    unordered_map<char, Trie*> map;
};

class InvertedIndex {
    private:
        Trie* root;

    public:

        InvertedIndex() {
            root = new Trie();
            root->isLeaf = false;
        }

        Trie* initializeTrie() {
            Trie* node = new Trie;
            node->isLeaf = false;

            return node;
        }

        void insert(const char* str, int index) {
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
            curr->v_set.insert(index);
        }

        set<int> search(const char* str) {

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
};


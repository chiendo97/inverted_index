#include <bits/stdc++.h>

using namespace std;

class InvertedIndex {
    private: 
        // nq: how many document has this query
        map<string, set<int>> nq;
        // fq: each document has how many of this query
        map<string, map<int, int>> fq;

    public:

        void add(string word, int docid) {
            nq[word].insert(docid);
            fq[word][docid] += 1;
        }

        int get_docuemnt_frequency(string word, int docid) {
            return fq[word][docid];
        }

        int get_index_frequency(string word) {
            return nq[word].size();
        }
        
        set<int> get_documents(string word) {
            return nq[word];
        }
};

class DocumentLengthTable {

    public:
        map<int, int> table;

        void add(int docid, int length) {
            table[docid] = length;
        }

        int get_length(int docid) {
            return table[docid];
        }

        double get_average_length() {
            double sum = 0;
            double size = 0;
            for (pair<int, int> element: table) {
                sum += element.second;
                size += 1;
            }
            
            return sum / size;
        }
};


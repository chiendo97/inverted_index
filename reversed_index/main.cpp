#include <bits/stdc++.h> 

#include "trie_struct.cpp"
#include "utilities.cpp"

using namespace std;

vector<string> strs;
InvertedIndex idx = InvertedIndex();

void input(const char* file_name) {
    ifstream cin(file_name);

    string s;

    while (getline(cin, s)) {
        strs.push_back(s);
    }
}

void preprocessing_document() {

    for (int i = 0; i < strs.size(); i++) {

        string str = strs[i];
        vector<string> tokens = split_by_space(str);

        for (string token: tokens) {

            token = remove_vietnameses_tone(token);
            token = tolowercase(token);

            idx.insert(token.c_str(), i);
        }
    }

}

vector<string> query(string keyword) {

    keyword = remove_vietnameses_tone(keyword);
    keyword = tolowercase(keyword);

    vector<string> query_tokens = split_by_space(keyword);

    set<int> result;

    for (int i = 0; i < strs.size(); i++) result.insert(i);
    for (string token: query_tokens) {

        set<int> result_token = idx.search(token.c_str());
        set<int> combine_result;
        set_intersection(result.begin(), result.end(), result_token.begin(), result_token.end(), inserter(combine_result, combine_result.begin()));

        result = set<int>(combine_result);
    }

    vector<string> final_result;

    for (int i: result) {
        final_result.push_back(strs[i]);
    }

    return final_result;
}

void test_with_100_query() {

    ifstream cin("100_query.txt");
    freopen("100_query_result.txt", "w", stdout);

    string s;
    while (getline(cin, s)) {
        vector<string> res = query(s);
        cout << s << endl;
        for (string re: res) cout << re << endl; 
        cout << endl;
    }
}

void custom_test() {

    while (true) {
        string keyword;
        getline(cin, keyword);

        vector<string> res = query(keyword);
        for (string re: res) cout << re << endl;
        cout << endl;
    }
}

int main(int argc, char** argv) {

    clock_t tStart = clock();

    if (argc == 1) { return 0; }

    const char* file_name = argv[1];
    
    input(file_name);

    printf("Read document: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    preprocessing_document();

    printf("Preprocessing document: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0;
}


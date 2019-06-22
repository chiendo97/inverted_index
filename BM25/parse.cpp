#include <bits/stdc++.h>

using namespace std;

vector<string> document_parse(const char* file_name) {
    ifstream cin(file_name);
    vector<string> strs;

    string s;
    while (getline(cin, s)) {
        strs.push_back(s);
    }

    return strs;
}




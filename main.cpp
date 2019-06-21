#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> input(string file_name) {
    freopen("product_names.txt", "r", stdin);
    vector<string> strs;

    string s;
    while (getline(cin, s)) {
        strs.push_back(s);
    }

    return strs;
}

int main(int argc, char** argv) {

    if (argc == 1) { return 0; }

    string file_name = argv[1];
    
    vector<string> strs;
    strs = input(file_name);

    cout << strs.size() << endl;

    return 0;
}


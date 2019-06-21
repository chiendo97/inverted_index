#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_set<int> s1;
    s1.insert(0);
    s1.insert(1);
    s1.insert(2);
    unordered_set<int> s2;
    s2.insert(1);
    s2.insert(2);
    unordered_set<int> s3;

    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s3, s3.begin()));

    s1 = unordered_set<int>(s3);

    for (int i: s1) {
        cout << i << endl;
    }

    return 0;
}


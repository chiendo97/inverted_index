#include <codecvt>
#include <locale>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s = "LÊ TIẾN CHIẾN";
    for(size_t i = 0; i < s.length();)
    {
        int cplen = 1;
        if((s[i] & 0xf8) == 0xf0) cplen = 4;
        else if((s[i] & 0xf0) == 0xe0) cplen = 3;
        else if((s[i] & 0xe0) == 0xc0) cplen = 2;
        if((i + cplen) > s.length()) cplen = 1;

        string res;
        for (int j = 0; j < cplen; j++) {
            res.push_back(s[i+j]);
        }
        cout << res << endl;
        i += cplen;
    }
}

#include <codecvt>
#include <locale>
#include <bits/stdc++.h> 

using namespace std;

vector<string> arr1({"á", "à", "ả", "ã", "ạ", "â", "ấ", "ầ", "ẩ", "ẫ", "ậ", "ă", "ắ", "ằ", "ẳ", "ẵ", "ặ",  "đ",  "é","è","ẻ","ẽ","ẹ","ê","ế","ề","ể","ễ","ệ",  "í","ì","ỉ","ĩ","ị",  "ó","ò","ỏ","õ","ọ","ô","ố","ồ","ổ","ỗ","ộ","ơ","ớ","ờ","ở","ỡ","ợ",  "ú","ù","ủ","ũ","ụ","ư","ứ","ừ","ử","ữ","ự",  "ý","ỳ","ỷ","ỹ","ỵ"});
vector<string> arr2({"Á", "À", "Ả", "Ã", "Ạ", "Â", "Ấ", "Ầ", "Ẩ", "Ẫ", "Ậ", "Ă", "Ắ", "Ằ", "Ẳ", "Ẵ", "Ặ",  "Đ",  "É","È","Ẻ","Ẽ","Ẹ","Ê","Ế","Ề","Ể","Ễ","Ệ",  "Í","Ì","Ỉ","Ĩ","Ị",  "Ó","Ò","Ỏ","Õ","Ọ","Ô","Ố","Ồ","Ổ","Ỗ","Ộ","Ơ","Ớ","Ờ","Ở","Ỡ","Ợ",  "Ú","Ù","Ủ","Ũ","Ụ","Ư","Ứ","Ừ","Ử","Ữ","Ự",  "Ý","Ỳ","Ỷ","Ỹ","Ỵ"});
vector<char> arr3({'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',  'd',  'e','e','e','e','e','e','e','e','e','e','e',  'i','i','i','i','i',  'o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o',  'u','u','u','u','u','u','u','u','u','u','u',  'y','y','y','y','y'});

string remove_vietnameses_tone(string s) {
    
    string result;

    int n = s.length();
    for(size_t i = 0; i < n;)
    {
        // read by utf-8 encoding
        int cplen = 1;
        if((s[i] & 0xf8) == 0xf0) cplen = 4;
        else if((s[i] & 0xf0) == 0xe0) cplen = 3;
        else if((s[i] & 0xe0) == 0xc0) cplen = 2;
        if((i + cplen) > s.length()) cplen = 1;

        string ch;
        for (int j = 0; j < cplen; j++) {
            ch.push_back(s[i+j]);
        }

        bool check = true;
        for (int i = 0; i < arr1.size(); i++) {
            if (ch == arr1[i] || ch == arr2[i]) {
                result.push_back(arr3[i]);
                check = false;
                break;
            }
        }
        if (check) result.push_back(ch[0]);

        i += cplen;
    }

    return result;
}

string tolowercase(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    return s;
}

vector<string> split_by_space(const string& s) {

   vector<string> tokens;
   string token;
   stringstream ss(s); 

   while (ss >> token) {
       tokens.push_back(token);
   }
   return tokens;
}


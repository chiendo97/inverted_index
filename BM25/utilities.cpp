#include <codecvt>
#include <locale>
#include <bits/stdc++.h> 

using namespace std;

unordered_map<string, char> vn_tones = {{"á", 'a'},{"à", 'a'},{"ả", 'a'},{"ã", 'a'},{"ạ", 'a'},{"â", 'a'},{"ấ", 'a'},{"ầ", 'a'},{"ẩ", 'a'},{"ẫ", 'a'},{"ậ", 'a'},{"ă", 'a'},{"ắ", 'a'},{"ằ", 'a'},{"ẳ", 'a'},{"ẵ", 'a'},{"ặ", 'a'},{"đ", 'd'},{"é", 'e'},{"è", 'e'},{"ẻ", 'e'},{"ẽ", 'e'},{"ẹ", 'e'},{"ê", 'e'},{"ế", 'e'},{"ề", 'e'},{"ể", 'e'},{"ễ", 'e'},{"ệ", 'e'},{"í", 'i'},{"ì", 'i'},{"ỉ", 'i'},{"ĩ", 'i'},{"ị", 'i'},{"ó", 'o'},{"ò", 'o'},{"ỏ", 'o'},{"õ", 'o'},{"ọ", 'o'},{"ô", 'o'},{"ố", 'o'},{"ồ", 'o'},{"ổ", 'o'},{"ỗ", 'o'},{"ộ", 'o'},{"ơ", 'o'},{"ớ", 'o'},{"ờ", 'o'},{"ở", 'o'},{"ỡ", 'o'},{"ợ", 'o'},{"ú", 'u'},{"ù", 'u'},{"ủ", 'u'},{"ũ", 'u'},{"ụ", 'u'},{"ư", 'u'},{"ứ", 'u'},{"ừ", 'u'},{"ử", 'u'},{"ữ", 'u'},{"ự", 'u'},{"ý", 'y'},{"ỳ", 'y'},{"ỷ", 'y'},{"ỹ", 'y'},{"ỵ", 'y'},{"Á", 'a'},{"À", 'a'},{"Ả", 'a'},{"Ã", 'a'},{"Ạ", 'a'},{"Â", 'a'},{"Ấ", 'a'},{"Ầ", 'a'},{"Ẩ", 'a'},{"Ẫ", 'a'},{"Ậ", 'a'},{"Ă", 'a'},{"Ắ", 'a'},{"Ằ", 'a'},{"Ẳ", 'a'},{"Ẵ", 'a'},{"Ặ", 'a'},{"Đ", 'd'},{"É", 'e'},{"È", 'e'},{"Ẻ", 'e'},{"Ẽ", 'e'},{"Ẹ", 'e'},{"Ê", 'e'},{"Ế", 'e'},{"Ề", 'e'},{"Ể", 'e'},{"Ễ", 'e'},{"Ệ", 'e'},{"Í", 'i'},{"Ì", 'i'},{"Ỉ", 'i'},{"Ĩ", 'i'},{"Ị", 'i'},{"Ó", 'o'},{"Ò", 'o'},{"Ỏ", 'o'},{"Õ", 'o'},{"Ọ", 'o'},{"Ô", 'o'},{"Ố", 'o'},{"Ồ", 'o'},{"Ổ", 'o'},{"Ỗ", 'o'},{"Ộ", 'o'},{"Ơ", 'o'},{"Ớ", 'o'},{"Ờ", 'o'},{"Ở", 'o'},{"Ỡ", 'o'},{"Ợ", 'o'},{"Ú", 'u'},{"Ù", 'u'},{"Ủ", 'u'},{"Ũ", 'u'},{"Ụ", 'u'},{"Ư", 'u'},{"Ứ", 'u'},{"Ừ", 'u'},{"Ử", 'u'},{"Ữ", 'u'},{"Ự", 'u'},{"Ý", 'y'},{"Ỳ", 'y'},{"Ỷ", 'y'},{"Ỹ", 'y'},{"Ỵ", 'y'}};

inline string remove_vietnameses_tone(string s) {
    
    string non_vn_tones_str;

    int n = s.length();
    for(size_t i = 0; i < n;)
    {
        // read follow by utf-8 encoding
        
        int cplen = 1;
        if((s[i] & 0xf8) == 0xf0) cplen = 4;
        else if((s[i] & 0xf0) == 0xe0) cplen = 3;
        else if((s[i] & 0xe0) == 0xc0) cplen = 2;
        if((i + cplen) > s.length()) cplen = 1;

        string word;
        for (int j = 0; j < cplen; j++) {
            word.push_back(s[i+j]);
        }

        if (vn_tones.find(word) == vn_tones.end()) {
            non_vn_tones_str.push_back(word[0]);
        } else {
            non_vn_tones_str.push_back(vn_tones[word]);
        }

        i += cplen;
    }

    return non_vn_tones_str;
}

inline string tolowercase(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    return s;
}

inline vector<string> split_by_space(const string& s) {

   vector<string> tokens;
   string token;
   stringstream ss(s); 

   while (ss >> token) {
       tokens.push_back(token);
   }
   return tokens;
}

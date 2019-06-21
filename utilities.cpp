#include <bits/stdc++.h> 

using namespace std;

vector<string> split_by_space(const string& s)
{
   vector<string> tokens;
   string token;
   stringstream ss(s); 

   while (ss >> token) {
       tokens.push_back(token);
   }
   return tokens;
}


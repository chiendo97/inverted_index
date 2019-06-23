#include <bits/stdc++.h>

#include "data_struct.cpp"
#include "utilities.cpp"

using namespace std;

const double k = 1.2;
const double b = 0.75;

clock_t tStart = clock();

vector<string> strs;
DocumentLengthTable dlt;
InvertedIndex idx;

void input(const char* file_name) {
    cout << "Staring read from file input! Estimate time: 1s" << endl;

    ifstream cin(file_name);

    string s;
    while (getline(cin, s)) {
        strs.push_back(s);
    }
}

void preprocessing_document() {
    cout << "Staring preprocessing document! Estimate time: 6-7s" << endl;


    for (int i = 0; i < strs.size(); i++) {
        vector<string> tokens = split_by_space(strs[i]);

        dlt.add(i, tokens.size());

        for (string token: tokens) {
            token = remove_vietnameses_tone(token);
            token = tolowercase(token);
            idx.add(token, i);
        }
    }
}

double score_BM25(double n, double f, double N, double dl, double avdl) {

    double IDF = log((N - n + 0.5) / (n + 0.5));
    double result = IDF * (f*(k+1) / (f + k * (1 - b + b * dl / avdl)));

    return result;
}

vector<pair<string, double>> query(string keyword) {
    cout << "Staring quering! Estimate time: 10-60s" << endl;


    keyword = remove_vietnameses_tone(keyword);
    keyword = tolowercase(keyword);

    vector<string> tokens = split_by_space(keyword);

    map<int, double> score;

    for (string token: tokens) {

        set<int> documents = idx.get_documents(token);

        for (int i: documents) {

            int freq = idx.get_docuemnt_frequency(token, i);
            int nq = idx.get_index_frequency(token);
            int dl = dlt.get_length(i);
            int avdl = dlt.get_average_length();

            score[i] += score_BM25(nq, freq, strs.size(), dl, avdl);
        }
    }

    vector<pair<double, int>> reverse_score;

    for (auto el: score) {
        reverse_score.push_back({el.second, el.first});
    }

    sort(reverse_score.begin(), reverse_score.end());

    vector<pair<string, double>> final_result;

    for (int i = reverse_score.size()-1; i >= 0; i--) {
        if (reverse_score[i].first > 0) 
            final_result.push_back({strs[reverse_score[i].second], reverse_score[i].first});
    }

    return final_result;
}

void custom_test() {

    while (true) {
        cout << "query: ";

        string keyword;
        getline(cin, keyword);

        vector<pair<string, double>> test = query(keyword);

        cout << setw(10) << "score_BM25" << setw(150) << "output_query" << endl << endl;
        for (auto p: test) {
            cout << setw(10) << p.second << setw(150) << p.first << endl;
        }

        printf("Query done: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

        cout << endl;
    }

}

void test_with_100_query() {
    cout << "Staring read and query file_query! Estimate time: 6000s" << endl;

    ifstream cin("100_query.txt");
    freopen("100_query_result.txt", "w", stdout);

    string s;
    while (getline(cin, s)) {
        vector<pair<string, double>> res = query(s);
        cout << s << endl;
        for (auto p: res) {
            cout << p.first << ' ' << p.second << endl;
        }
        cout << endl;

    }

}

int main(int argc, char** argv) {

    if (argc == 1) { return 0; }

    const char* file_name = argv[1];
    
    input(file_name);

    printf("Read document done: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    preprocessing_document();

    printf("Preprocessing document done: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    custom_test();

    printf("Test done: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}


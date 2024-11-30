#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> buildSuffixArray(const string &s) {
    int n = s.size();
    vector<int> suffix_array(n), rank(n), temp_rank(n);
    
    for (int i = 0; i < n; i++) {
        suffix_array[i] = i;
        rank[i] = s[i];
    }
    for (int k = 1; k < n; k *= 2) {
        auto comparator = [&](int i, int j) {
            if (rank[i] != rank[j])
                return rank[i] < rank[j];
            int rank_i_k = (i + k < n) ? rank[i + k] : -1;
            int rank_j_k = (j + k < n) ? rank[j + k] : -1;
            return rank_i_k < rank_j_k;
        };
        sort(suffix_array.begin(), suffix_array.end(), comparator);

        temp_rank[suffix_array[0]] = 0;
        for (int i = 1; i < n; i++) {
            temp_rank[suffix_array[i]] = temp_rank[suffix_array[i - 1]] + comparator(suffix_array[i - 1], suffix_array[i]);
        }
        rank = temp_rank;
    }
    
    return suffix_array;
}

vector<int> buildLCPArray(const string &s, const vector<int> &suffix_array) {
    int n = s.size();
    vector<int> lcp(n, 0), rank(n, 0);

    for (int i = 0; i < n; i++) {
        rank[suffix_array[i]] = i;
    }

    int h = 0;
    for (int i = 0; i < n; i++) {
        if (rank[i] > 0) {
            int j = suffix_array[rank[i] - 1];
            while (i + h < n && j + h < n && s[i + h] == s[j + h])
                h++;
            lcp[rank[i]] = h;
            if (h > 0)
                h--;
        }
    }

    return lcp;
}

int countDistinctSubstrings(const string &s) {
    int n = s.size();
    vector<int> suffix_array = buildSuffixArray(s);
    vector<int> lcp = buildLCPArray(s, suffix_array);

    int distinct_substrings = 0;
    for (int i = 0; i < n; i++) {
        int substr_count = n - suffix_array[i];
        distinct_substrings += substr_count - lcp[i];
    }
    
    return distinct_substrings;
}

int main() {
    string s;
    cin >> s;

    cout << countDistinctSubstrings(s) << endl;
    return 0;
}
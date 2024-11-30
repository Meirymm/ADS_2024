#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool hasCommonSubstring(const vector<string>& strings, int len, string& result) {
    unordered_set<string> substrings;
    
    const string& first_string = strings[0];
    for (size_t i = 0; i + len <= first_string.size(); ++i) {
        substrings.insert(first_string.substr(i, len));
    }

    for (size_t i = 1; i < strings.size(); ++i) {
        unordered_set<string> current_substrings;
        const string& current_string = strings[i];

        for (size_t j = 0; j + len <= current_string.size(); ++j) {
            string substring = current_string.substr(j, len);
            if (substrings.count(substring) > 0) {
                current_substrings.insert(substring);
            }
        }

        substrings = current_substrings;
        if (substrings.empty()) {
            return false;  // No common substring of this length across all strings
        }
    }

    result = *substrings.begin();
    return true;
}

string longestCommonSubstring(const vector<string>& strings) {
    int left = 0;
    int right = min_element(strings.begin(), strings.end(),
                            [](const string& a, const string& b) { return a.size() < b.size(); })->size();
    
    string longest_substring;

    while (left <= right) {
        int mid = (left + right) / 2;
        string current_substring;
        
        if (hasCommonSubstring(strings, mid, current_substring)) {
            longest_substring = current_substring;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return longest_substring;
}

int main() {
    int k;
    cin >> k;
    vector<string> strings(k);

    for (int i = 0; i < k; ++i) {
        cin >> strings[i];
    }

    cout << longestCommonSubstring(strings) << endl;
    return 0;
}
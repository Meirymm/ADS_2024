#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int n;  
    while (cin >> n && n != 0) {  
        vector<std::string> patterns(n);
        unordered_map<std::string, int> frequency;   
        
        for (int i = 0; i < n; ++i) {
           cin >> patterns[i];
        }

       
        string text;
        cin >> text;

        int max_freq = 0;  

        for (const auto& pattern : patterns) {
            int count = 0;
            size_t pos = text.find(pattern);

         
            while (pos != string::npos) {
                ++count;
                pos = text.find(pattern, pos + 1);
            }
            
            frequency[pattern] = count;
            max_freq = std::max(max_freq, count);
        }

       cout << max_freq << "\n";
        for (const auto& pattern : patterns) {
            if (frequency[pattern] == max_freq) {
                cout << pattern << "\n";
            }
        }
    }

    return 0;
}
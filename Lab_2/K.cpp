#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void findNonRepeating(int N, string stream) {
    unordered_map<char, int> freq; 
    queue<char> q;                 
    for (int i = 0; i < N; ++i) {
        char ch = stream[i];
        freq[ch]++;
        q.push(ch);

        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }
        if (!q.empty()) {
            cout << q.front() << " ";
        } else {
            cout << "-1 ";
        }
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T; 
    while (T--) {
        int N;
        cin >> N; 
        string stream;
        for (int i = 0; i < N; ++i) {
            char ch;
            cin >> ch;
            stream += ch; 
        }
        findNonRepeating(N, stream); 
    }
    return 0;
}

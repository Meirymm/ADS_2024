#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> ages(n);
    for (int i = 0; i < n; i++) {
        cin >> ages[i];
    }
    vector<int> result(n, -1);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        if 
          (!s.empty() && ages[s.top()] < ages[i]) {
            result[i] = ages[s.top()];
        }

          else if (!s.empty()) {
            result[i] = ages[s.top()];
         }

        s.push(i);
    }
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout<< endl;

    return 0;
}

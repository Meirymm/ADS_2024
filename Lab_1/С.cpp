#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to process a string and handle backspaces
string processString(const string &s) {
    stack<char> resultStack;

    for (char ch : s) {
        if (ch == '#') {
            if (!resultStack.empty()) {
                resultStack.pop(); // Handle backspace
            }
        } else {
            resultStack.push(ch); // Add character to stack
        }
    }

    // Convert stack to string
    string result;
    while (!resultStack.empty()) {
        result = resultStack.top() + result;
        resultStack.pop();
    }

    return result;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    // Process both strings
    string processedS1 = processString(s1);
    string processedS2 = processString(s2);

    // Compare and output result
    if (processedS1 == processedS2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}


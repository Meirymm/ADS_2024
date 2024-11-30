#include <iostream>
#include <deque>
#include <sstream>
#include <string>

using namespace std;

int main() {
    deque<int> d;
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        string command;
        iss >> command;

        if (command == "+") {
            int number;
            iss >> number;
            d.push_front(number);
        } else if (command == "-") {
            int number;
            iss >> number;
            d.push_back(number);
        } else if (command == "*") {
            if (d.empty()) {
                cout << "error" << endl;
            } else {
                int front = d.front();
                int back = d.back();
                cout << front + back << endl;
                d.pop_front();
                if (!d.empty()) {
                    d.pop_back();
                }
            }
        } else if (command == "!") {
            break;
        }
    }
    return 0;
}

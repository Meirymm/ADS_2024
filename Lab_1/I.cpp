#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string votes;
    cin >> votes;

    int sakayanagiCount = 0;
    int katsuragiCount = 0;

    // Count the number of 'S' and 'K'
    for (char c : votes) {
        if (c == 'S') {
            sakayanagiCount++;
        } else if (c == 'K') {
            katsuragiCount++;
        }
    }

    // Determine the winner
    if (sakayanagiCount > katsuragiCount) {
        cout << "SAKAYANAGI" << endl;
    } else {
        cout << "KATSURAGI" << endl;
    }

    return 0;
}

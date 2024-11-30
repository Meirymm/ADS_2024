#include <iostream>
#include <vector>
#include <cstdlib> 
using namespace std;

int main() {
    int n;
    cin >> n; 

    vector<int> digits(n);
    for (int i = 0; i < n; ++i) {
        cin >> digits[i]; 
    }

    int x;
    cin >> x; 

    int index = 0;
    int minDistance = abs(digits[0] - x);

    for (int i = 1; i < n; ++i) {
        int distance = abs(digits[i] - x);
        if (distance < minDistance) {
            minDistance = distance;
            index = i;
        }
    }

    cout << index << endl; 

    return 0;
}
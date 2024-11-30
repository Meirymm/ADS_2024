#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false; // Числа меньше или равные 1 не являются простыми
    if (n == 2) return true;  // 2 является простым числом
    if (n % 2 == 0) return false; // Все четные числа, кроме 2, не являются простыми
    
    // Проверяем делители от 3 до корня из n
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false; 
        }
    }
    return true; 
}

int main() {
    int n;
    cin >> n;

    if (isPrime(n)) {
        cout << "YES" << endl;
    } else {
        cout  << "NO" << endl;
    }

    return 0;
}

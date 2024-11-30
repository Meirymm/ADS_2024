
#include <iostream>
#include <vector>
using namespace std;

// Функция для поиска всех простых чисел до определенного лимита с использованием решета Эратосфена
vector<int> sieve(int quantity) {
    vector<bool> is_prime(quantity + 1, true); // Массив для пометки простых чисел
    vector<int> primes;  // Массив для хранения всех найденных простых чисел
    
    is_prime[0] = is_prime[1] = false;  // 0 и 1 не являются простыми числами
    
    for (int i = 2; i <= quantity; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);  // Добавляем простое число в список
            for (int j = i * 2; j <= quantity; j += i) {
                is_prime[j] = false;  // Помечаем все кратные числа как непростые
            }
        }
    }
    return primes;
}

int main() {
    int n;
    cin >> n;

    // Устанавливаем разумный лимит для поиска первых 1000 простых чисел
    int quantity = 10000;
    
    // Получаем список простых чисел до заданного предела
    vector<int> primes = sieve(quantity);

    // Выводим n-е простое число
    cout <<  primes[n - 1] << endl;

    return 0;
}
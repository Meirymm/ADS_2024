#include <iostream>
#include <vector>
using namespace std;

// Функция для поиска всех простых чисел до определенного лимита с использованием решета Эратосфена
vector<int> sieve(int limit) {
    vector<bool> is_prime(limit + 1, true);  // Массив для пометки простых чисел
    vector<int> primes;  // Массив для хранения всех найденных простых чисел

    is_prime[0] = is_prime[1] = false;  // 0 и 1 не являются простыми числами

    for (int i = 2; i <= limit; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);  // Добавляем простое число в список
            for (int j = i * 2; j <= limit; j += i) {
                is_prime[j] = false;  // Помечаем все кратные числа как непростые
            }
        }
    }
    return primes;
}

int main() {
    int n;
    cin >> n;

    // Устанавливаем разумный лимит для поиска достаточно больших простых чисел
    int limit = 10000;

    // Получаем список простых чисел до заданного предела
    vector<int> primes = sieve(limit);

    // Находим n-е простое число (индексация начинается с 0)
    int nth_prime = primes[n - 1];

    // Находим простое число с индексом nth_prime (индексация начинается с 1)
    int super_prime = primes[nth_prime - 1];

    // Выводим результат
    cout << super_prime << endl;

    return 0;
}
//В теории чисел сильное простое число - это простое число,
// которое больше, чем среднее арифметическое ближайшего простого числа сверху и снизу
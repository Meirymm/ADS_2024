
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;  // Количество людей
    vector<int> ages(n);  // Вектор возрастов
    
    for (int i = 0; i < n; i++) {
        cin >> ages[i];  // Ввод возраста каждого человека
    }
    
    vector<int> result(n, -1);  // Инициализация результата значениями -1
    stack<int> s;  // Стек для хранения индексов

    for (int i = 0; i < n; i++) {
        // Удаляем всех людей из стека, чей возраст больше или равен текущему
        while (!s.empty() && ages[s.top()] >= ages[i]) {
            s.pop();
        }
        
        // Если стек не пуст, то ближайший человек младше текущего находится на вершине стека
        if (!s.empty()) {
            result[i] = ages[s.top()];
        }

        // Добавляем текущего человека в стек (его индекс)
        s.push(i);
    }
    
    // Выводим результат
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

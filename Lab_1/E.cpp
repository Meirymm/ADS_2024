#include <iostream>
#include <queue>
using namespace std;


void playGame(queue<int>& boris, queue<int>& nursic) {
    int max_moves = 1000000;  
    int moves = 0;  

    while (!boris.empty() && !nursic.empty() && moves < max_moves) {
        int b_card = boris.front();  
        int n_card = nursic.front(); 

        boris.pop();  
        nursic.pop(); 

        // Логика определения победителя:
        if ((b_card == 0 && n_card == 9) || (b_card > n_card && !(b_card == 9 && n_card == 0))) {
            boris.push(b_card);  // Борис кладет свою карту
            boris.push(n_card);  // Затем карту Нурсика
        } else {
            nursic.push(b_card);  // Нурсик кладет карту Бориса 
            nursic.push(n_card);  // Затем свою карту
        }

        moves++;  
    }

    if (boris.empty()) {
        cout << "Nursik " << moves << endl;  // Нурсик победил
    } else if (nursic.empty()) {
        cout << "Boris " << moves << endl;   // Борис победил
    } else {
        cout << "blin nichya" << endl;      
    }
}

int main() {
    queue<int> boris, nursic;  
    int card;
    for (int i = 0; i < 5; ++i) {
        cin >> card;
        boris.push(card);
    }
    for (int i = 0; i < 5; ++i) {
        cin >> card;
        nursic.push(card);
    }

    playGame(boris, nursic);

    return 0;
}


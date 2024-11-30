# include <cassert>
#include <list>
#include <set>
#include <iostream>
using namespace std;

int main() {
    list <std::string> list;
    long int a, move;
    cin >> a >> move;
    for(long int i = 0 ; i < a; i++){
        string s;
        cin >> s;
        list.push_back(s);
    }
    for(long int i = 0; i < move; i++){
        list.push_back(list.front());
        list.pop_front();
    }
    for(long int i = 0 ; i < a; i++){
        cout << list.front() << " ";
        list.pop_front();
    }
}

#include <iostream>
#include <deque>

using namespace std;
int main(){
    int n; 
    cin >> n;
    deque <int> deq;
    string s;
    while(n != 0){
        int a;
        cin >> a;
        int facto = (a  * (a - 1)) / 2 ;
        deq.push_front(a);
        if(a - 1 != 0){
                deq.push_front(a - 1);
        }
        int k = a - 1; 
        int i = 0; 
        while(facto != 0){
            if(k == i){
              
                i = 0;
                k--;  
                deq.push_front(k);
            }
            int back = deq.back(); 
            deq.pop_back(); 
            deq.push_front(back); 
            i++;
            facto--;
        }
        while(deq.empty() == false){
        cout << deq.front() << " ";
        deq.pop_front();
        }
        cout << endl;
        n--;
    }
} 


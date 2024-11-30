#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main(){
    string s; cin >> s;
    stack<char> st;

    for (int i = 0 ; i < s.size();i++){
        if(st.empty() == false && st.top() == s[i]){
            st.pop();
        }else{
            st.push(s[i]);
        }
    }
    if(st.empty() == true ){
        cout << "YES";
    }else{
        cout << "NO";
    }
}

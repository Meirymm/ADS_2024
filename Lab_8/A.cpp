#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
#define numm long long

string Hash(string s, int x = 1e9 + 7, int y = 11){
    numm p = 1; numm res = 0;
    for(int i = 0; i < s.size(); i++){
        res = (res + ((s[i] - 47) * p) % x) % x;
        p = (p * y) % x;
    }
    return to_string(res);
}


int main(){
    int n, cnt = 0; 
    cin >> n;
    vector <string> v;
    map <string, string> mp;

    for(int i = 0; i < n*2; i++){
        string s; cin >> s;
        v.push_back(s);
        mp.insert({s, Hash(s)});
    }

    for(auto i : v){
        string str = Hash(i);
        if(mp.find(str) != mp.end()){
            cout << "Hash of string \"" << i << "\" is " << str << "\n";
            cnt++;
        }
        if(cnt == n){
            break;
        }
    }
}
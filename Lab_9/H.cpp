#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define ll long long
vector<ll> LCP(string str){
  vector<ll> pi(str.size(), 0);
    
  for(ll i = 1; i < str.size(); i++){
    ll j = pi[i-1];
    while(j > 0 and str[i] != str[j])j = pi[j-1];
    if(str[i] == str[j])j++;
    pi[i] = j;
  }
  return pi;
}

int main(){
  string str;cin >> str;
  vector<ll> pi = LCP(str);
  int count = 0;
  for(int i = 1; i < str.size()-1; i+=2){
    if((i+1)%(i+1-pi[i]) == 0 and ((i+1)/(i+1-pi[i]))%2 == 0) count++;
  }
  cout << count;          

  return 0;    
}
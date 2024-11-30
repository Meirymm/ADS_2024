#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> LPS(string str){
  vector<int> pi(str.size());
  pi[0] = 0;
  int i = 1, j = 0;
  while(i < str.size()){
    if(str[i] == str[j]) pi[i++] = ++j;
    else if(j == 0)pi[i++] = 0;
    else j = pi[j-1];
  }
  return pi;
}

int main(){
  string str;cin >> str;
  vector<int> pi = LPS(str);
    
  cout << str.size()-pi[str.size()-1];
    
  return 0;
}
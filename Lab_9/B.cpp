#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<size_t> Answer(string str){
  size_t len = str.length();
  vector<size_t> vec(len);
  vec[0] = 0;
  for(size_t i = 1; i < len; ++i){
    size_t j = vec[i - 1];
    while(j > 0 && str[j] != str[i]) {
      j = vec[j-1];
    }

    if(str[i] == str[j]){
      vec[i] = j + 1;
    }
  }
  return vec;
}

int main(){
  int k;
  int cnt=0;
  string old;
  string new_pass;

  cin >> old >> k;
  cin >> new_pass;

  string str = old + '#'  + new_pass;

  vector<size_t> vec = Answer(str);

  for(int i = 0; i < vec.size(); ++i){
    if(vec[i] == old.size()) cnt++;
  }

  if(cnt >= k) cout << "YES"<< endl;
  else cout << "NO" << endl;
}
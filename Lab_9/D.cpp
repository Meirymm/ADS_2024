#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> pref(string str){
  vector<int> pi(str.size());
  pi[0] = 0;
  int i = 1, j = 0;
  while(i < str.size()){
    if (tolower(str[i]) == tolower(str[j])) pi[i++] = ++j;
    else if (j == 0) pi[i++] = 0;
    else j = pi[j-1];
  }
  return pi;
}

int main(){
  string str;
  int k;
  cin >> str >> k;
  vector<pair<string, int>> vec;
  int maximum = 0;
  while(k--){
    string str_p;
    cin >> str_p;
    vector<int> pi = pref(str_p + '#' + str);
    maximum = max(maximum, pi[pi.size()-1]);
    vec.push_back({str_p, pi[pi.size()-1]});
  }

  vector<string> res;
  for(pair<string, int> p : vec){
    if(maximum != 0 and maximum == p.second)res.push_back(p.first);
  }
  cout << res.size() << endl;
  for(string x : res) cout << x << endl;
}
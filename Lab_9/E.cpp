#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> LCP(string str){
  vector<int> pi(str.size());
  pi[0] = 0;
  int i = 1, j = 0;
  while(i < str.size()){
    if(str[i] == str[j]) pi[i++] = ++j;
    else if (j == 0) pi[i++] = 0;
    else j = pi[j-1];
  }
  return pi;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        string str;
        cin >> str;
        int k;
        cin >> k;
        int answer = str.size(), r = LCP(str)[str.size() - 1];
        answer += (k - 1) * (str.size() - r);
        cout << answer << endl;
    }

}
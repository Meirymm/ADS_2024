#include <iostream>
#include <string>
using namespace std;

void compute_LPS_array(string str, int *lps) {
  lps[0]=0;
  int len=0,i=1;
  int m = str.size();
  while(i<m) {
    if(str[i] == str[len]) {
      len++;
      lps[i]=len;
      i++;
    } else {
      if(len!=0) {
        len=lps[len-1];
      }
      else {
        lps[i]=0;
        i++;
      }
    }
  }
}
int kmp_searching(string str, string str_re) {
  int m = str.size();
  int n = str_re.size();
  int lps[m];
  compute_LPS_array(str, lps);
  int i = 0,j = 0;
  while(i<n) {
    if(str[j] == str_re[i]) {
      j++;
      i++;
    }
    if(j == m) {
      return i-m;
      j = lps[j-1];
    }
    else if(i < n && str[j] != str_re[i]){
      if(j == 0) i++;
      else j = lps[j-1];
    }
  }
  return -1;
}
int main() {
  string str_re, str;
  cin >> str_re >> str;
  int answer = kmp_searching(str, str_re + str_re);
  if(answer != -1) cout << str_re.size() - answer; 
  else cout << answer;
  
  return 0;
 }
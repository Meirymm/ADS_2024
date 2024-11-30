#include <iostream>
#include <vector>
using namespace std;

void Dfs(vector<vector<char> > & v, int i, int j){
  if(i > v.size() - 1 || j > v[0].size() - 1 || i < 0 || j < 0 || v[i][j] != '1') return;
  v[i][j] = '2';
  Dfs(v, i + 1, j);
  Dfs(v, i, j + 1);
  Dfs(v, i, j - 1);
  Dfs(v, i - 1, j);
}

int numI(vector<vector<char> > & v){
  int n = v.size();
  int m = v[0].size();
  int cnt = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (v[i][j] == '1'){
        cnt++;
        Dfs(v, i, j);
      }
    }
  }
  return cnt;
}

int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<char> > V;
  for (int i = 0; i < n; i++){
    vector<char> v1;
    for (int j = 0; j < m; j++){
      char num;
      cin >> num;
      v1.push_back(num);
    }
    V.push_back(v1);
  }
  cout << numI(V);

  return 0;
} 
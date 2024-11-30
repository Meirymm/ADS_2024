#include<bits/stdc++.h>
using namespace std;
bool b[10000];

int Dfs(vector<int> vec[], int k, int n){
  if(b[k]==true) return 0;
  int d[n + 1];
  int visit[n + 1];
  for(int i = 0; i <= n; i++){
    d[i] = -1;
    visit[i] = false;
  }
  queue<int> q;
  q.push(k);
  d[k] = 0;
  visit[k] = 1;
  
  while(!q.empty()){
    int curr = q.front();
    q.pop();
    for(int i = 0; i < vec[curr].size(); i++){
      if(visit[vec[curr][i]] == 0){
        visit[vec[curr][i]] = 1;
        d[vec[curr][i]] = d[curr] + 1;
        q.push(vec[curr][i]);
        if(b[vec[curr][i]] == true){
          return d[vec[curr][i]];
        }
      }
    } 
  }
  return -1;
}

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> vec[n+1]; 
  for(int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    vec[x].push_back(y);
    vec[y].push_back(x);
  }
  for(int i=0;i<q;i++) {
    int x,y;
    cin >> x >> y;
    if(x == 1) b[y] = true;
    else cout << Dfs(vec, y, n) << endl;
  }
  return 0;
}
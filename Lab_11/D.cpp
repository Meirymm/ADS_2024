#include <bits/stdc++.h>
using namespace std;

int parameter[10000];

int find(int i){
  if(i == parameter[i])
	return i;
  return parameter[i] = find(parameter[i]); 
}

void merge(int i, int j){
  parameter[find(i)] = parameter[find(j)];
}

int main() {
	int n; cin >> n;
  int g[n][n];
  int cnt = 0;
  vector<pair<int, pair<int, int> > > v;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++) {
      cin >> g[i][j];
      v.push_back({g[i][j], {i, j}});
    }
  }
  sort(v.begin(), v.end());
  long long cost = 0;
  for (int i = 0; i < n; i++) parameter[i] = i;
  for (auto e : v){
    if (find(e.second.first) != find(e.second.second)) {
      cost += e.first;
      merge(e.second.first, e.second.second);
    }
  }
    
	cout << cost;
}
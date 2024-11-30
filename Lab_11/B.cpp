#include <bits/stdc++.h>
using namespace std;
#define max_v 100000
int n;
vector<pair<int, pair<int, int> > > v;
int parameter[max_v];

int find(int i){
  if(i == parameter[i])return i;
  return parameter[i] = find(parameter[i]);
}

void merge(int i, int j){
  int a = find(i), b = find(j);
  parameter[a] = parameter[b];

}

int main(){
  cin >> n;
  int d[n];
  for (int i = 0; i < n; i++) cin >> d[i];

  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (i != j) v.push_back({d[i]+d[j], {i, j}});
    }
  }

  for (int i = 0; i < n; i++) parameter[i] = i;
  sort(v.begin(), v.end());
  long long min_cost = 0;
  for (auto e : v) {
    int i = e.second.first, j = e.second.second, c = e.first;
    if(find(i) != find(j)){
      min_cost += c;
      merge(i, j);
    }
  }

  cout << min_cost;
}
#include <bits/stdc++.h>
using namespace std;

int p[200000], r[200000];

int find(int i) {
  return (i == p[i]) ? i : p[i] = find(p[i]);
}

bool merge(int i, int j) {
  int a = find(i);
	int b = find(j);
  if(a == b) return false;
  p[a] = b;
  return 1;
}

int main() {
	int n, m;
  cin >> n >> m;
  int used[n];
  vector<int> ans;
  vector<int> g[n];
  for(int i = 0; i < n; i++) {
		p[i] = i;
		r[i] = i;
	}
  while(m--) {
    int i, j;
    cin >> i >> j;
    i--;j--;
    g[i].push_back(j);
    g[j].push_back(i);
  }

  int cnt = 0;
  for(int i = n-1; i >= 0; i--) {
    ans.push_back(cnt++);
    for(int x : g[i]) {
      if(x > i) {
        if(merge(i, x)) cnt--;
      }
    }
  }

  for(int i = ans.size()-1; i >= 0; i--) cout << ans[i] <<endl;  
}

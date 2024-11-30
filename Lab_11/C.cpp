#include <bits/stdc++.h>
using namespace std;

int n, m, x, y;

vector<pair<int, pair<int, int> > > v;
int parameter[10000];

int find(int i) {
  if(i == parameter[i])	
  return i;
  return parameter[i] = find(parameter[i]);
}

void merge(int i, int j) {
  int a = find(i); int b = find(j);
  parameter[a] = parameter[b];
}

int main(){
  cin >> n >> m >> x >> y;
  while(m--) {
    string s;
		int a, b, c;
    cin >> s >> a >> b >> c;
    if(s == "both")
		v.push_back({c*min(x,y), {a, b}});
    else if(s == "small")
		v.push_back({c*y, {a, b}});
    else if(s == "big")
		v.push_back({c*x, {a, b}});
  }

  sort(v.begin(), v.end());
  for(int i = 0; i < n; i++)
	parameter[i] = i;
  long long mincost = 0;
  for(auto e : v) {
    int l = e.second.second, r = e.second.first, c = e.first;
    if(find(l) != find(r)) {
			mincost += c;
      merge(l, r);
    }
  }

  cout << mincost;
}
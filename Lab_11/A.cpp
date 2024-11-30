#include <bits/stdc++.h>
using namespace std;
#define maxn 200007
#define f first
#define s second
int n, m;
int l, r, c;
vector<pair<int, pair<int, int> > > v; 
int par[maxn];
int la[maxn], ra[maxn];

int find(int i) {
  if(i == par[i])
	return i;
  return par[i] = find(par[i]);
}
void color(vector<bool> &used, int l, int r) {
  for(int i = l; i <= r; i++)
	used[i] = 1;
}
bool merge(int i, int j) {
  int a = find(i), b = find(j);
  if(a == b) return false;
  par[a] = b;
  la[b] = min(la[a], la[b]);
  ra[b] = max(ra[a], ra[b]);
  return 1;
}

int main() {
  cin >> n >> m; 
	vector<bool> used(n, false);

  while(m--) {
    cin >> l >> r >> c;
    l--;r--;
    v.push_back({c, {l, r}});
  }
  for(int i = 0; i < n; i++) {
    par[i] = i;
    la[i] = i;
    ra[i] = i;
  }
  sort(v.begin(), v.end());
  long long mincost = 0;
  int cnt = 0, po = -1;
  for(int i = 0; i < v.size(); i++) {
    if(cnt > n-1)	break;
    int l = v[i].s.f, r = v[i].s.s, c = v[i].f;
    po = l;
    for(int j = l; j <= r; j++) {
      if(j != find(j)) {
        po = find(j);
        break;
      }
    }
    if(la[po] <= l and r <= ra[po])	continue;
    else if(la[po] <= r and r <= ra[po]) r = la[po];
    else if(la[po] <= l and l <= ra[po]) l = ra[po];
    for(int j = l; j <= r; j++) {
      if(merge(po, j)) {
        cnt++;
        mincost += c;
      }
    }
  }
	cout << mincost;
}

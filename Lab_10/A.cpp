#include <bits/stdc++.h>
using namespace std;
int main(){
  int m, n;
  cin >> m >> n;
  int mr = 0, time = 0;
  int matrix[m+2][n+2];
  vector < pair <int, int>> mario;
  for (int i = 0; i < m + 2; i++) {
		for (int j = 0; j < n + 2; j++) {
			if (i == 0 || j == 0 || i == m + 1 || j == n + 1) {
				matrix[i][j] = 1000;
				continue;
			}
			cin >> matrix[i][j];
			if (matrix[i][j] == 2) mario.push_back({ i, j });
      else if (matrix[i][j] == 1)	mr++;
		}
	}
  queue < pair<int, int>> q;
  for(int i = 0; i < mario.size(); i++) q.push({mario[i].first, mario[i].second});
  while(!q.empty()){
    if(mr == 0) break;
    int s = q.size();
    while(s--){
      pair <int, int> pos = q.front();
      q.pop();
      int i = pos.first;
			int j = pos.second;
			if (matrix[i - 1][j] == 1) {
				matrix[i - 1][j] = 2;
				q.push({ i - 1, j });
				mr--;
			}
			if (matrix[i + 1][j] == 1) {
				matrix[i + 1][j] = 2;
				q.push({ i + 1, j });
				mr--;
			}
			if (matrix[i][j - 1] == 1) {
				matrix[i][j - 1] = 2;
				q.push({ i, j - 1 });
				mr--;
			}
			if (matrix[i][j + 1] == 1) {
				matrix[i][j + 1] = 2;
				q.push({ i, j + 1 });
				mr--;
			}
    }
    time++;
  }
  if(mr == 0) cout << time;
  else cout << -1;
  return 0;
}
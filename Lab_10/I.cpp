#include <bits/stdc++.h>
using namespace std;
vector < vector < int>> qwe;
vector <bool> used;
vector <int> topSort, color;

bool d(int vertex) {
	color[vertex] = 1;
	for (int i = 0; i < qwe[vertex].size(); i++) {
		if (color[qwe[vertex][i]] == 1) {
			return true;
		}
		if (color[qwe[vertex][i]] == 0) {
			if (d(qwe[vertex][i])) return true;
		}
	}
	color[vertex] = 2;
	return false;
}

void topsort(int vertex) {
	used[vertex] = true;
	for (int i = 0; i < qwe[vertex].size(); i++) {
		if (!used[qwe[vertex][i]]) {
			topsort(qwe[vertex][i]);
		}
	}
	topSort.push_back(vertex);
}

int main() {
	int m, n;
	cin >> m >> n;
	color.resize(m);
	qwe.resize(m);
	used.resize(m);
	int u, v;
	for (int i = 0; i < n; i++) {
		cin >> u >> v;
		u--; v--;
		qwe[u].push_back(v);
	}
	bool hasCycle = false;
	for (int i = 0; i < m; i++) {
		if (d(i)) {
			hasCycle = true;
			break;
		}
	}
	if (!hasCycle) {
		cout << "Possible" << endl;
		for (int i = 0; i < m; i++) {
			if (!used[i]) {
				topsort(i);
			}
		}
		for (int i = topSort.size() - 1; i >= 0; i--) {
			cout << topSort[i] + 1 << " ";
		}
	} else {
		cout << "Impossible";
	}

	return 0;
}
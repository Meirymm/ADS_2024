#include <bits/stdc++.h>
using namespace std;
int n, m;
vector < vector <int>> qwe;
vector <int> color;

bool cycle(int vertex, pair <int, int> e){
    color[vertex] = 1;
    for(int i = 0; i < qwe[vertex].size(); i++){
        if(vertex == e.first && qwe[vertex][i] == e.second){
            continue;
        }
        if(color[qwe[vertex][i]] == 1){
            return true;
        }
        if(color[qwe[vertex][i]] == 0){
           if(cycle(qwe[vertex][i], e)){
            return true;
           }
        }
    }
    color[vertex] = 2;
    return false;
}
int main(){
    cin >> n >> m;
    qwe.resize(n);
    color.resize(n);
    int u, v;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        u--; v--;
        qwe[u].push_back(v);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < qwe[i].size(); j++){
            bool noCycle = true;
            for(int k = 0; k < n; k++){
                if(cycle(k, {i, qwe[i][j]})){
                    noCycle = false;
                    break;
                }
            }
            if(noCycle){
                cout << "YES";
                return 0;
            }
        color.assign(n, 0);
        }
    }
    cout << "NO";
    return 0;
}
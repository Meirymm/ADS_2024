#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
vector < vector <int>> qwe;
vector <bool> used;
bool DFS(int vertex){
    if(vertex == y){
        return true;
    }
    used[vertex] = true;
    for(int i = 0; i < qwe[vertex].size(); i++){
        if(!used[qwe[vertex][i]]){
            if(DFS(qwe[vertex][i])){
                return true;
            }
        }
    }
    return false;
}
int main(){
    cin >> n >> m;
    qwe.resize(n);
    used.resize(n);
    int u, v;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        u--; v--;
        qwe[u].push_back(v);
        qwe[v].push_back(u);
    }
    cin >> x >> y;
    x--; y--;
    if(DFS(x)){
        cout << "YES";
    } else{
        cout << "NO";
    }
    return 0;
}
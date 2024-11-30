#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    int start, end;
    cin >> start >> end;
    int len = 0;
    start--; end--;
    if(start == end){
        cout << len;
        return 0;
    }
    queue <int> q;
    vector <bool> used(n);
    q.push(start);
    used[start] = true;
    while(!q.empty()){
        int cur = q.front();
        len++;
        for(int i = 0; i < n; i++){
            if(!used[i] && a[cur][i]){
                if(i == end){
                    cout << len;
                    return 0;
                }
                used[i] = true;
                q.push(i);
            }
        }
        q.pop();
    }
    cout << -1;
    return 0;
}
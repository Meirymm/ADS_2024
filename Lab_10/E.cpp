#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, q;
    cin >> n >> q;
    int a[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    int x, y, z;
    while(q--){
        cin >> x >> y >> z;
        x--; y--; z--;
        if(a[x][y] == 0 || a[x][z] == 0 || a[y][z] == 0){
            cout << "NO" << endl;
        } else{
            cout << "YES" << endl;
        }
    }
}
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> v(n);
    vector <int> v2;
    v2.push_back(-1);
    for(int i = 0 ; i < n; i++){
        cin >> v[i];
    }
    for(int i = 1; i < n; ++i) {
        int cnt = 0;
        for (int j = i - 1; j >= 0; --j){
            cnt++;
            if (v[i] >= v[j]){
                v2.push_back(v[j]);
                break;
            }if(cnt == i){
                v2.push_back(-1);
            }
        }
    }
    for(int i = 0 ; i < v2.size(); i++){
        cout << v2[i] << " ";
    }
}
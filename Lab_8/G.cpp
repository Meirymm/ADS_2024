#include <iostream>
#include <vector>
#include <algorithm>
using namespace  std;

string sub(int l, int r, string s){
    string sum;
    for(int i=l-1; i<=r-1; i++){
        sum+=s[i];
    }
    return sum;
}

int count(string& pat, string& txt)
{
    int M = pat.length(); //2
    int N = txt.length(); //6
    int res = 0;
    for (int i = 0; i <= N - M; i++) { /// qaqzaq
        int j;
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j]) //  aq
                break;
        if (j == M) {
            res++;
        }
    }
    return res;
}

int c(string& p, string& t){
    int res=0; int n = t.size(); int m = p.size();
    for(int i=0; i<=n-m; i++){
        int j;
        for(j=0; j<m; j++){
            if(t[i+j] != p[j]) break;
        }
        if(j==m) res++;
    }
    return res;
}

int main(){
    string s;
    cin >> s;
    int n; cin >> n;
    int l, r;
    vector<string> v;
    for(int i=0; i<n; i++){
        cin >> l >> r;
        v.push_back(sub(l, r, s));
    }

    for(int i=0; i<n; i++){
        cout << c(v[i], s) << endl;
    }
}
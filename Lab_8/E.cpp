#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    long long h;
    vector<long long> HASH;

    for(int i=0;i<n;i++){
        cin>>h;
        HASH.push_back(h);
    }


    vector<long long>::iterator it1;
    for(it1 = HASH.begin(); it1 < HASH.end(); it1++){
        h = *it1;
        if(it1 != HASH.begin())
            h -= *(it1-1);

        h /= pow(2, it1-HASH.begin());
        h += 97;
        cout<<(char)h;
    }
}
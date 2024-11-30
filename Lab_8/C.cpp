#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
const int q=100003, d =13;

int solve(string s, string key, int *a)
{
    int count = 0;
    int z= 0, p= 0, h= 1;
    for (int i=0;i < key.size()-1;i++)
    {
        h = (h*d) % q;
    }
    for (int i=0;i<key.size();i++)
    {
        z= ((d*z) + (s[i] - 47)) % q;
        p= ((d*p) + (key[i] - 47)) % q;
    }
    for (int i = 0; i <= s.size() - key.size(); i++)
    {
    if (z==p)
        {
            int j;
            for (j = 0; j < key.size(); j++)
            {   
                if(s[i+j]!=key[j]){
                    break;
                }
                if (a[i + j] == 0)
                {
                    count++;
                    a[i + j] = 1;
                }
            }
            if(j!=key.size())
        count==0;
        }
        
        if (i < s.size() - key.size())
        {
           z= (d * (z- (s[i] - 47) * h) + (s[i + key.size()] - 47)) % q;
            if (z< 0)
               z+= q;
        }
    }
    return count;
}

int main()
{
    string s; cin >> s;
    int n; cin >> n;
    int count = 0;
    
    int a[s.size()] = {0};
    for (int i=0;i<n;i++)
    {
        string key;cin >> key;
        count += solve(s, key, a);
    }
    if(count == s.size())
    {
      cout<<"YES";
  }
  else
  {
    cout<<"NO";
  }
}
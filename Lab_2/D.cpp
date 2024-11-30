#include<iostream>
#include<algorithm>
#include<set>
# include <cassert>
#include<vector>
using namespace std;
int main()
{
  int n;cin>>n;
  vector<int> v;
  vector<int> result;
  set<int> s;
  for(int i=0;i<n;i++)
  {
    int x;cin>>x;
    v.push_back(x);
    s.insert(x);
  }
  int cnt=0;
  for(auto it =s.begin();it != s.end();it++)
  {
    int cnt2=0;
    for(int i=0;i<v.size();i++)
    {
      if(*it ==v[i])
      {
        cnt2++;
      }
    }
    if(cnt2>cnt)
    {
      cnt=cnt2;
      result.clear();
      result.push_back(*it);
    }
    else if(cnt2==cnt)
      {
        result.push_back(*it);
    }
  }
    reverse(result.begin(),result.end());
  for(auto const &i:result)
  {
    cout<<i<<" ";
  }
  return 0;
 }
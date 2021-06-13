#include <bits/stdc++.h>
using namespace std;



int main() {
  int n;
  cin>>n;
  vector<int>v(n);
  for(int i = 0;i<n;i++)
  {
    cin>>v[i];
  }
  stack<pair<int,int>> s;
  s.push(make_pair(-1,0));
  vector<int>ans(n, 0);
  for(int i = 0;i<n;i++)
  {
    pair<int,int>p = make_pair(v[i],i+1);
    while(s.top().first >= p.first )
    {
      s.pop();
    }
    ans[i] = s.top().second;
    s.push(p);
  }
  for(int i = 0;i<n;i++)
  {
    cout<<ans[i]<<" ";
  }
  cout<<endl;
  return 0;
  
}
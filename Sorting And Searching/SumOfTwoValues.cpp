#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,x;
  cin>>n>>x;
  vector<pair<int, int>>v(n);
  for (int i =0;i<n;i++)
  {
    int k;
    cin>>k;
    v[i] = make_pair(2*k - x, i);
  }
  sort(v.begin(), v.end());
  int i = 0;
  int j = n-1;
  while(i<j)
  {
    int a = v[i].first;
    int b = v[j].first;
    if (a+b == 0)
    {
      vector<int>ans(2);
      ans[0] = v[i].second+1;
      ans[1] = v[j].second+1;
      sort(ans.begin(), ans.end());
      cout<<ans[0] << " "<< ans[1]<<"\n";
      return 0;
    }
    else if (a+b>0)
    {
      j--;
    }
    else
    {
      i++;
    }
  }
  cout<<"IMPOSSIBLE\n";
  return 0;
}
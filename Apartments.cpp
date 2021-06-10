#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,m,k;
  cin>>n>>m>>k;

  vector<pair<int, int>>v(n);
  vector<int> apart(m);
  for(int i =0 ;i<n;i++)
  {
    int s;
    cin>>s;
    v[i] = make_pair(s-k, s+k);
  }
  for(int i = 0;i<m;i++)
  {
    cin>>apart[i];
  }
  sort(v.begin(), v.end());
  sort(apart.begin(), apart.end());
  int i = 0, j = 0, count = 0;
  while (i<v.size() && j<apart.size())
  {
    if (v[i].first<=apart[j] && v[i].second>=apart[j])
    {
      count++;
      i++;
      j++;
    }
    else if (v[i].first>apart[j])
    {
      j++;
    }
    else if (v[i].second<apart[j])
    {
      i++;
    }
  }
  cout<<count<<endl;
  return 0;
}
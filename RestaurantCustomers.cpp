#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin>>n;
  vector<pair<int, int>>v(2*n);
  for(int i = 0;i<n;i++)
  {
    int a, b;
    cin>>a>>b;
    v[2*i] = make_pair(a,1);
    v[2*i+1] = make_pair(b,-1);
  }
  sort(v.begin(), v.end());
  int count = 0;
  int max_count = 0;
  for(int i = 0;i<v.size();i++)
  {
    if(v[i].second == 1)
    {
      count++;
    }
    else
    {
      count--;
    }
    max_count = max(max_count, count);
  }
  cout<<max_count<<endl;
  return 0;
}
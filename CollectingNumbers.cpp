#include <bits/stdc++.h>
using namespace std;
int main() {
  // Number of points a[i]>a[i+1];
  int n;
  cin>>n;
  vector<pair<int, int> >v(n);
  for(int i = 0;i<n;i++)
  {
    int k;
    cin>>k;
    v[i] = make_pair(k,i);
  }
  sort(v.begin(), v.end());
  if (v.size() == 1)
  {
    cout<<1<<endl;
    return 0;
  }
  int count = 0;
  for(int i = 0;i<v.size()-1;i++)
  {
    if (v[i].second>v[i+1].second)
    {
      count++;
    }

  }
  cout<<count+1<<endl;
  return 0;
}
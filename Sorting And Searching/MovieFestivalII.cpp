#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  set <pair<int, int>> s;
  int n,k;
  cin>>n>>k;
  vector<pair<int,int>> end_start_times(n);
  for(int i = 0;i<n;i++)
  {
    int a, b;
    cin>>a>>b;
    end_start_times[i] = make_pair(b,a);
  }
  
  sort(end_start_times.begin(), end_start_times.end());
  // for(auto i: end_start_times)
  // {
  //   cout<<"[ "<<i.second<<","<<i.first<<" ] ";
  // }++
  int count = 0;
  for(int i = 0; i<n;i++)
  {
    if (s.size() ==0 )
    {
      s.insert(make_pair(-end_start_times[i].first, i));
      count++;
      continue;
    }
    auto it = s.lower_bound(make_pair(-end_start_times[i].second, -1));
    if (it!=s.end())
    {
      s.erase(it);
      s.insert(make_pair(-end_start_times[i].first, i));
      count++;
    }
    else if (s.size()<k)
    {
      s.insert(make_pair(-end_start_times[i].first, i));
      count++;
    }
  }
  cout<<count<<endl; 
  return 0;
  
}
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin>>n;
  vector<pair<int,int>>end_start_times(n);
  for(int i = 0;i<n;i++)
  {
    int a, b;
    cin>>a>>b;
    end_start_times[i] = make_pair(b,a);
  }
  sort(end_start_times.begin(), end_start_times.end());
  int count = 0;
  int cur_time = -1;
  for(int i = 0;i<end_start_times.size();i++)
  {
    int start_time = end_start_times[i].second;
    if (start_time >=cur_time)
    {
      cur_time = end_start_times[i].first;
      count++;
    }
  }
  cout<<count<<endl;
  return 0;
}
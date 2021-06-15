#include <bits/stdc++.h>
using namespace std;



int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  queue<int> s;
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
  int count = 0;
  for(int i = 0;i<k;i++)
  {
    s.push(0);
  }
  for(int i = 0; i<n;i++)
  {
    if(s.front()<end_start_times[i].second)
    {
      count++;
      s.pop();
      s.push(end_start_times[i].first);
    }
  }
  cout<<count<<endl; 
  return 0;
  
}
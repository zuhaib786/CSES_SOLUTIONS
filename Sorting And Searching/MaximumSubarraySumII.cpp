


#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  set<pair<long long int, int>> s;
  int n, a, b;
  cin>>n>>a>>b;
  vector<int>v(n);
  for(int i = 0;i<n;i++)
  {
    cin>>v[i];
  }
  vector<long long int>prefix_sum(n+1, 0);
  for(int i =0 ;i<n;i++)
  {
    prefix_sum[i+1] = prefix_sum[i] + v[i];
  }
  for(int i = a; i<=b;i++)
  {
    s.insert(make_pair(prefix_sum[i], i));
  }
  auto it = s.end();
  it--;
  long long int max_sum = (*it).first;
  for(int i = 1;i<n-a+1;i++)
  {
      s.erase(s.find(make_pair(prefix_sum[i+a-1], i+a-1)));
      if(i+b<=n)
      {
          s.insert(make_pair(prefix_sum[i+b], i+b));
      }
      auto it  = s.end();
      it--;
      max_sum = max(max_sum , (*it).first - prefix_sum[i]);
  }
  cout<<max_sum<<endl;
  return 0;
  
}
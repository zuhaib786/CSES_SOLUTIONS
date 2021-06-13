#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,x;
  cin>>n>>x;
  vector<int>v(n);
  for(int i = 0;i<n;i++)
  {
    cin>>v[i];
  }
  // => # Subarrays ending at b with sum x = #i such that 
  // sum[0:i] = sum[0:b] - x 
  map<long long int, long long int> m;
  long long int cur_sum  = 0;
  long long int count = 0;
  for(int i = 0;i<n;i++)
  {
    cur_sum += v[i];
    if (cur_sum == x)
    {
      count++;
    }
    if (m.find(cur_sum-x)!= m.end())
    {
      count+= m[cur_sum-x];
    }
    m[cur_sum]++;
  }
  cout<<count<<endl;
  return 0;
  
}
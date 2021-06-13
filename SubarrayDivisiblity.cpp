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
  map<long long int, long long int> m;
  long long int cur_sum  = 0;
  long long int count = 0;
  for(int i = 0;i<n;i++)
  {
    cur_sum += v[i];
    if (((cur_sum%n)+n)%n == 0)
    {
      count++;
    }
    if (m.find(((cur_sum%n)+n)%n)!= m.end())
    {
      count+= m[((cur_sum%n)+n)%n];
    }
    m[((cur_sum%n)+n)%n]++;
  }
  cout<<count<<endl;
  return 0;
  
}
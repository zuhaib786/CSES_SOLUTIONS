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
  sort(v.begin(), v.end());
  int opt = v[(n-1)/2];
  long long int cost = 0;
  for(int i = 0;i<n;i++)
  {
    cost += abs(v[i] - opt);
  }
  cout<<cost<<endl;
  return 0;
}
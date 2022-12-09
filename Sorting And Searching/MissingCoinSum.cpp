#include <bits/stdc++.h>
using namespace std;
int main() {
  // minimum element that cannot be expressed as a sum of a subset in a sorted array
  int n;
  cin>>n;
  vector<int>v(n);
  for( int i = 0; i<n;i++)
  {
    cin>>v[i];
  }
  sort(v.begin(), v.end());
  if (v[0]!=1)
  {
    cout<<1<<endl;
    return 0 ;
  }
  long long int sum = 1;
  for (int i = 0;i<n;i++)
  {
    if (sum<v[i])
    {
      cout<<sum<<endl;
      return 0;
    }
    sum = sum+v[i];
  }
  cout<<sum<<endl;
  return 0;
}
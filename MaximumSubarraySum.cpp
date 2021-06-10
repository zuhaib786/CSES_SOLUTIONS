#include <bits/stdc++.h>
using namespace std;
int main() {
  //kadane Algo
  int n;
  cin>>n;
  int v[n];
  for(int i =0 ;i<n;i++)
  {
    cin>>v[i];
  }
  long long int sum = 0;
  long long int max_sum =*(max_element(v+0, v+n));
  for(int i = 0;i<n;i++)
  {
    if (sum+v[i]<0)
    {
      sum = 0;
    }
    else
    {
      sum = sum+v[i];
      max_sum = max(max_sum, sum);
    }
  }
  cout<<max_sum<<endl;
  return 0;
}
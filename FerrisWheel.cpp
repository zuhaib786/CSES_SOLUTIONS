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
  sort(v.begin(), v.end());
  int count = 0;
  int left = 0;
  int right = v.size()-1;
  while(left<=right)
  {
    if (left == right)
    {
      count++;
      left++;
      right--;
      continue;
    }
    if (v[left]+v[right]<=x)
    {
      right--;
      left++;
      count++;
    }
    else
    {
      count++;
      right--;
    }
  }
  cout<<count<<endl;
  return 0;
}
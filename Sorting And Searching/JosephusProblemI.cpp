#include <bits/stdc++.h>
using namespace std;
vector<int> solve(int n,  bool include)
{
    //using recursion
  if (n==1)
  {
    vector<int> v(n);
    v[0] = 1;
    return v;
  }
  vector<int> v(n);
  if (!include)
  {
    for(int i = 2; i<n+1;i+=2)
    {
      v[i/2-1] = i;
    }
    vector<int> temp;
    if (n%2 == 0)
    {
      
      temp = solve(n/2, include);
      for(int i = 0;i<temp.size();i++ )
      {
        v[i+ n/2] = temp[i]*2 - 1;
      }
      
    }
    else
    {
     
      temp = solve(n/2+1, !include);
      for(int i = 0;i<temp.size();i++)
      {
       
        v[i+n/2] = temp[i]*2 - 1;
      }
      
    }
  }
  else
  {
    for(int i = 1; i<n+1;i+=2)
    {
      v[i/2] = i;
    }
    vector<int> temp;
    if (n%2 == 0)
    {
      
      temp = solve(n/2, include);
      for(int i = 0;i<temp.size();i++)
      {

        v[i+n/2] = 2*temp[i];
      }
      
    }
    else
    {
      
      temp = solve(n/2, !include);
      for(int i = 0;i<temp.size();i++)
      {
    
        v[i+n/2+1] = 2*temp[i];
      }
     
    }
  }
  return v;
}
int main() {
  int n;
  cin>>n;
  vector<int> v = solve(n, false);
  for(int i = 0;i<n;i++)
  {
    cout<<v[i]<<" ";
  }
  cout<<endl;
  return 0;
}
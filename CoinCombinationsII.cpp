#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000007
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(NULL); 
  int n,x;
  cin>>n>>x;
  set<int>coin_values;
  for(int i = 0;i<n;i++)
  {
      int k;
      cin>>k;
      coin_values.insert(k);
  }
  vector<int>dp(x+1, 0);
  dp[0] = 1;
  
  for(auto j: coin_values)
  {
    for(int i = 1; i<=x;i++)
    {
      if (j<=i)
      {
        dp[i] += dp[i-j];
        dp[i] %=MAX;
      }
    }
  }   
  cout<<dp[x]<<endl;
}
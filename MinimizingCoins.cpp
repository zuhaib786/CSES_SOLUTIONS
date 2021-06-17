#include <bits/stdc++.h>
using namespace std;
#define MAX 10000009
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(NULL); 
  int n,x;
  cin>>n>>x;
  vector<int>coin_values(n);
  for(int i = 0;i<n;i++)
  {
      cin>>coin_values[i];
  }
  vector<int>dp(x+1, MAX);
  dp[0] = 0;
  
  for(auto j: coin_values)
  {
    for(int i = 1; i<=x;i++)
    {
        int minima = dp[i];
        if (j<=i)
        {
            minima = min(minima, dp[i-j]+1);
        }
        dp[i] = minima;
    }
  }
  if (dp[x]>=MAX)
  {
      cout<<-1<<endl;
  }
  else
  {
      cout<<dp[x]<<endl;
  }
}
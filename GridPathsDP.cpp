#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000007
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(NULL); 
  int n;
  cin>>n;
  vector<string>v(n);
  for(int i = 0;i<n;i++)
  {
      cin>>v[i];
  }
  vector<vector<int>>dp(n);
  for(int i= 0;i<n;i++)
  {
      vector<int>temp(n,0);
      dp[i] = temp;
  }
  if(v[0][0]=='*')
  {
     dp[0][0] == 0; 
  }
  else
  {
      dp[0][0] = 1;
  }
  for(int i = 0;i<n;i++)
  {
      for(int j = 0;j<n;j++)
      {
          if(v[i][j] == '*')
          {
              dp[i][j] = 0;
          }
          else
          {
              if(i>0)
              {
                  dp[i][j]+=dp[i-1][j];
                  dp[i][j]%= MAX;
              }
              if (j>0)
              {
                  dp[i][j]+=dp[i][j-1];
                  dp[i][j]%=MAX;
              }
          }
      }
  }
  cout<<dp[n-1][n-1]<<endl;
}
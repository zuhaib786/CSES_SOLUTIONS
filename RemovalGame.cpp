#include<bits/stdc++.h>
#define MAX 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i = 0;i<n;i++)
    {
        cin>>v[i];
    }
    long long int prefix_sum[n+1] = {0};
    for(int i = 0;i<n;i++)
    {
        prefix_sum[i+1] = prefix_sum[i] + v[i];
    }
    long long int dp[n][n][2];
    for(int i =n-1; i>=0;i--)
    {
       for(int j=i; j<n;j++)
       {
           if(i==j)
           {
               dp[i][j][0] = v[i];
               dp[i][j][1] = 0;
           }
           else
           {
               long long int val1 = dp[i+1][j][1]+v[i];
               long long int val2 = dp[i][j-1][1]+v[j];
               dp[i][j][0] = max(val1, val2);
               if(dp[i][j][0] == val1)
               {
                   dp[i][j][1] = dp[i+1][j][0];
               }
               else
               {
                   dp[i][j][1] = dp[i][j-1][0];
               }   
           }
       }
    }
    // for(int i = 0;i<n;i++)
    // {
    //     for(int j = i;j<n;j++)
    //     {
    //         cout<<"["<<dp[i][j][0]<<", "<<dp[i][j][1]<<"] ";
    //     }
    //     cout<<endl;
    // }
    
    cout<<dp[0][n-1][0]<<endl;
    return 0;
}

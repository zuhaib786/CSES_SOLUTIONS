#include<bits/stdc++.h>
#define MAX 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    int n, m;
    cin>>n>>m;
    vector<int>v(n);
    for(int i = 0;i<n;i++)
    {
        cin>>v[i];
    }
    vector<vector<long long int>>dp(n);
    for(int i = 0;i<n;i++)
    {
           
        dp[i] = vector<long long int>(m+1,0);
    }
    for(int i = 0;i<n;i++)
    {
        if(v[i] == 0)
        {
            if (i==0)
            {
                int index = 0;
                while(index< n && v[index]==0)
                {
                    index++;
                }
                if (index == n)
                {
                    dp[i] = vector<long long int> (m+1,1);
                    dp[i][0] = 0;
                   
                }
                else
                {
                    dp[i] = vector<long long int> (m+1, 0);
                    for(int j = max(1,v[index]-index); j<=min(m, v[index]+index);j++ )
                    {
                        dp[i][j] = 1;
                    }
                }
            }
            else
            {
                for(int j=1;j<=m;j++)
            {
                if (j<m)
                    dp[i][j] = dp[i-1][j-1]+ dp[i-1][j]+ dp[i-1][j+1];
                else
                    dp[i][j] = dp[i-1][j-1]+ dp[i-1][j];
                dp[i][j] %= MAX;        
            }
            }
        }
        else
        {
            if (i==0)
            {
                dp[i][v[i]] = 1;
                continue;
            }
            dp[i][v[i]] = dp[i-1][v[i]]+dp[i-1][v[i]-1];
            if (v[i]<m)
            {
                dp[i][v[i]]+= dp[i-1][v[i]+1];
            }
            dp[i][v[i]] %= MAX;
        }
    }
    long long int ans = 0;
    for(int i = 1;i<=m;i++)
    {
        ans+=dp[n-1][i];
        ans%= MAX;
    }
    cout<<ans<<endl;
}

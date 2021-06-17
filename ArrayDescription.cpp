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
    vector<vector<int>>dp(n+1);
    for(int i = 0;i<=n;i++)
    {
        if (i==0)
            dp[i] = vector<int>(m+1,0);
        else    
            dp[i] = vector<int>(m+1,0);
    }
    // dp[i][j] = Number of arrays [0-i-1] such that v[i-1] = j;
    dp[0][0] = 1;
    for(int i = 1;i<=n;i++)
    {
        if(v[i-1] == 0)
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
        else
        {
            dp[i][v[i-1]] = dp[i-1][v[i]]+dp[i-1][v[i-1]-1];
            if (v[i-1]<m)
            {
                dp[i][v[i-1]]+= dp[i-1][v[i-1]+1];
            }
            dp[i][v[i-1]] %= MAX;
        }
    }
    int ans = 0;
    for(vector<int> vec : dp)
    {
        cout<<"[";
        for(int i: vec)
        {
            cout<<i<<" , ";
        }
        cout<<"]\n";
    }
    for(int i = 1;i<=m;i++)
    {
        ans+=dp[n][i];
        ans%= MAX;
    }
    cout<<ans<<endl;
}
/*
3 5
0 1 2
[1,0, 0 , 0 , 0]
[0, 0, 1,0,0]
[0,1 , 1, 1, 0]
[0,0,3,]
*/
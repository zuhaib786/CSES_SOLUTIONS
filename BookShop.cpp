#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    int n,x;
    cin>>n>>x;
    vector<int>h(n);
    vector<int>s(n);

    for(int i = 0;i<n;i++)
    {
        cin>>h[i];
    }

    for(int i = 0;i<n;i++)
    {
        cin>>s[i];
    }
    vector<vector<long long int>> dp(2);
    for(int i = 0;i<2;i++)
    {
        dp[i] = vector<long long int>(x+1, 0);
    }
    for(int i = 1; i <=n; i++)
    {
        for(int price  = 1;price<=x;price++)
        {
            if (price >= h[i-1])
            {
                dp[1][price] = max(dp[0][price - h[i-1]]+s[i-1], dp[0][price]);
            }
            else
            {
                dp[1][price] = dp[0][price];
            }
        }
        for(int j = 0; j<x+1;j++)
        {
            dp[0][j] = dp[1][j];
        }
    }
    cout<<dp[1][x]<<endl;

}

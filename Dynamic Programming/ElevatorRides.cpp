#include<bits/stdc++.h>
#define MAX 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,x;
    cin>>n>>x;
    vector<int>weights(n);
    for(int i = 0; i<n;i++)
    {
        cin>>weights[i];
    }
    vector<pair<int, int>>dp(1<<n);
    dp[0] = make_pair(0,x);
    for(int i = 1;i<1<<n;i++)
    {
        dp[i] = make_pair(n+1,0);
        for(int j = 0; j<n;j++)
        {
            if(i&(1<<j))
            {
                auto temp = dp[i^(1<<j)];
                if(temp.second + weights[j]<=x)
                {
                    temp.second+=weights[j];
                }
                else
                {
                    temp.first++;
                    temp.second = weights[j];
                }
                dp[i] = min(dp[i], temp);
            }
        }
    }
    cout<<dp[(1<<n)-1].first<<endl;
    return 0;
}   

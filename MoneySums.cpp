#include<bits/stdc++.h>
#define MAX 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    int n;
    cin>>n;
    int sum = 0;
    vector<int>v(n);
    for(int i = 0;i<n;i++)
    {
        cin>>v[i];
        sum+=v[i];
    }
    bool dp[sum+1][n] = {false};
    for(int i = 0; i<n;i++)
    {
        dp[0][i] = true;
    }
    int count = 0;
    string ans = "";
    for(int i = 1; i<=sum;i++)
    {
        //dp[s][i] = dp[s][i-1]||dp[s-v[i]][i-1]
        for (int j = 0; j<n;j++)
        {
            if(j==0)
            {
                if(i==v[j])
                {
                    dp[i][j] = true;
                }
                else
                {
                    dp[i][j] = false;
                }
                continue;
            }
            if (i>=v[j])
            {
                dp[i][j] = dp[i][j-1]||dp[i-v[j]][j-1];
            }
            else
            {
                dp[i][j] = dp[i][j-1];
            }
        }
        if(dp[i][n-1])
        {
            count++;
            ans+= to_string(i)+" ";
        }
    }
    cout<<count<<endl;
    cout<<ans<<endl;
    return 0;
}

#include<bits/stdc++.h>
#define MAX 1000000007
long long int dp[1000007][2];

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    string s1, s2;
    cin>>s1>>s2;
    int dp[s1.size()+1][s2.size()+1] = {0};
    for(int i = 0;i<=s1.size();i++)
    {
        dp[i][0] = i;
    }
    for(int i = 0;i<=s2.size();i++)
    {
        dp[0][i] = i;
    }
    for(int i = 1; i<= s1.size();i++)
    {
        for(int j = 1; j<=s2.size();j++)
        {
            if (s1[i-1]==s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = min(min(dp[i-1][j]+1, dp[i][j-1]+1), dp[i-1][j-1]+1);
            }
        }
    }
    cout<<dp[s1.size()][s2.size()]<<endl;
    return 0;
}

#include<bits/stdc++.h>
#define MAX 1000000007
long long int dp[1000007][2];
void precalc()
{
    dp[1][0] = 1;
    dp[1][1] =1;
    for(int i = 2;i<=1000006;i++)
    {
        dp[i][0] = ((4*dp[i-1][0])%MAX+dp[i-1][1])%MAX;
        dp[i][1] = (dp[i-1][0]+(2*dp[i-1][1])%MAX)%MAX;
    }
}
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    int t;
    cin>>t;
    precalc();
    while(t--)
    {
        int n;
        cin>>n;
        cout<<(dp[n][0]+dp[n][1])%MAX<<endl;
    }
    return 0;
}

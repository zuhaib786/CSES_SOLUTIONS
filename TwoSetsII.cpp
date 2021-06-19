#include<bits/stdc++.h>
#define MAX 1000000007
#define INV 500000004
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    map<pair<int, int>, long long int> m;
    int n;
    cin>>n;
    int sum = n*(n+1);
    if (sum%4 !=0)
    {
        cout<<0<<endl;
        return 0;
    }
    long long int dp[sum/4+1][n+1] = {0};
    for(int i = 0; i<=n;i++)
    {
        dp[0][i] = 1;
    }
    for(int i = 1; i<=sum/4;i++)
    {
        for(int j = 1; j<= n; j++)
        {
            if (i>=j)
            {
                dp[i][j] = dp[i-j][j-1]+ dp[i][j-1];
                dp[i][j]%= MAX;
            }
            else
            {
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    cout<< (dp[sum/4][n]*INV)%MAX<<endl;
    return 0;
}   

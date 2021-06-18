#include<bits/stdc++.h>
#define MAX 1000000007
int dp[501][501];
using namespace std;
int minima(int x, int y)
{
    int minimum = MAX;
    for(int i = 1; i<x;i++)
    {
        minimum = min(dp[i][y]+dp[x-i][y]+1, minimum);
    }
    for(int j = 1; j<y; j++)
    {
        minimum = min(dp[x][j]+dp[x][y-j]+1, minimum);
    }
    return minimum;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    int a, b;
    cin>>a>>b;
    for(int i = 1;i<=a;i++)
    {
        dp[i][1] = i-1;
    }
    for(int i = 1;i<=b;i++)
    {
        dp[1][i] = i-1;
    }
    for(int x =2; x<=a;x++)
    {
        for(int y = 2; y<=b;y++)
        {
            if (x==y)
            {
                dp[x][y] = 0;
            }
            else
                dp[x][y] = minima(x, y);
        }
    }
    cout<<dp[a][b]<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
const int maxN = 10;
const int maxM = 1000;
const int mod = 1e9 + 7;
int n, m;
lli dp[(1<<maxN)][2];

void place_blocks(int mask, int column, int next_row_mask)
{
    if (column >= n)
    {
        if(column == n)
        {
            // Placing the blocks was successfull
            dp[next_row_mask][1] += dp[mask][0];
            dp[next_row_mask][1] %= mod;
        }
        return;
    }
    if (mask&(1<<column))
    {
        // current column is filed. You cannot place anything here 
        place_blocks(mask, column + 1, next_row_mask);
    }
    else{
        // current column is empty. 
        place_blocks(mask, column + 1, next_row_mask |(1<<column));// place vertical block here
        if (! (mask &(1<<(column + 1))) && column + 1 < n)// next block is also empty
        {
           
            place_blocks(mask, column + 2, next_row_mask);
        }
    }
}

void precalc()
{
    memset(dp, 0, sizeof(dp));
    // dp[0][1] = 1;
    dp[(1<<n) - 1][0] = 1;
    for(int j = 0; j <= m; j++)
    {
        for(int mask = 0; mask < (1<<n); mask++)
        {
            place_blocks(mask, 0, 0);
        }
        for(int i = 0; i < (1<<n); i++)
        {
            dp[i][0] = dp[i][1];
            dp[i][1] = 0;
        }
    }
}

int main()
{
    cin>>n>>m;
    precalc();
    cout<<dp[0][0]<<'\n';
}
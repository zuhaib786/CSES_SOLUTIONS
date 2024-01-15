#include<bits/stdc++.h>
using namespace std;
using lli = long long int;

const int maxN = 2e5 + 5;
int telep[maxN];
int dp[maxN];
int visited[maxN];
int tin[maxN];

int dfs(int i, int count){
   
    if(visited[i])
    {
        if (dp[i] == maxN)
        {
            dp[i] = count - tin[i];
            return i + 1;
        }
        else
            return 0;
    }
    else
    {
        tin[i] = count;
        visited[i] = 1;
        int val = dfs(telep[i], count + 1);
        if (val == 0)
        {
            dp[i] = min(dp[i], dp[telep[i]] + 1);
        }
        else
        {
            dp[i] = min(dp[i], dp[telep[i]]);
        }
        return val == i + 1 ? 0: val;
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        dp[i] = maxN;
    }
    memset(visited, 0, sizeof(visited));
    memset(tin, 0 ,sizeof(tin));
    for(int i = 0; i < n; i++)
    {
        cin>>telep[i];
        telep[i]--;
    }
    for(int i =0; i< n; i++)
    {
        if(visited[i] == 0)
        {
            dfs(i, 0);
        }
    }
    for(int i = 0; i< n; i++)
    {
        cout<<dp[i]<< " ";
    }
    cout<<endl;
    
}
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>dp;
void dfs(vector<vector<int>>&adj, int vertex,int par)
{
    for(auto x: adj[vertex])
    {
        if(x!=par)
        {
            dfs(adj, x, vertex);
            dp[vertex][0] += max(dp[x][0], dp[x][1]);
        }
         
    }
    for(auto x: adj[vertex])
    {
        if(x!=par)
            dp[vertex][1] = max(dp[vertex][1], 1 + dp[vertex][0] - max(dp[x][0], dp[x][1]) + dp[x][0] );
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<vector<int>>adj(n);
    dp = vector<vector<int>>(n, vector<int>(2,0));
    for(int i = 0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(adj,0,-1);
    cout<<max(dp[0][0], dp[0][1])<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>&adj, int vertex, vector<int>&subordinates)
{
    for(auto x: adj[vertex])
    {
        dfs(adj,x, subordinates);
        subordinates[vertex]+=1;
        subordinates[vertex]+=subordinates[x];
    }
    return;
}
int main()
    {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        cout.tie(NULL);
        int n;
        cin>>n;
        vector<vector<int>>adj(n);
        for(int i = 0;i<n-1;i++)
        {
            int x;
            cin>>x;
            x--;
            adj[x].push_back(i+1);
        }
        vector<int>subordinates(n,0);
        dfs(adj,0,subordinates);
        for(auto x: subordinates)
        {
            cout<<x<<" ";
        }
        cout<<endl;
        return 0;
    }
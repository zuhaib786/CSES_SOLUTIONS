#include <bits/stdc++.h>
using namespace std;
int a = 0;
int b = -1;
int c = -1;
vector<int>distances;
void dfs(vector<vector<int>>&adj, int vertex,int par)
{
    for(auto x: adj[vertex])
    {
        if(x!=par)
        {
            distances[x] = distances[vertex] +1;
            dfs(adj, x, vertex);
            
        }
         
    }
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
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    distances = vector<int>(n,0);
    dfs(adj,0,-1);
    b = 0;
    for(int i = 0; i<n;i++)
    {
        if(distances[b]<distances[i])
        {
            b = i;
        }
    }
    distances = vector<int>(n,0);
    dfs(adj, b, -1);
    for(auto x: distances)
    {
        c = max(c, x);
    }
    cout<<c<<endl;
    return 0;
}
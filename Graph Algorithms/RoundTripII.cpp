#include<bits/stdc++.h>
#define MAX 1000000007
using namespace std;
pair<int, int> cycle_node = make_pair(-1,-1);
void printSet(set<int> &s)
{
    cout<<"[ ";
    for(auto x:s)
    {
        cout<<x<<" ";
    }
    cout<<"]"<<endl;
}
void dfs(vector< vector<int>>&nodes, vector<int>&visited, set<int> &ancestors, vector<int>&previous, int vertex)
{
    if(cycle_node != make_pair(-1,-1))
    {
        return;
    }
    if(visited[vertex]==1)
    {
        return ;
    }
    // printSet(ancestors);
    // cout<<"Node: "<<vertex<<endl;
    visited[vertex] = 1;
    ancestors.insert(vertex);
    for(int x: nodes[vertex])
    {
        if(ancestors.find(x)!= ancestors.end())
        {

            cycle_node = make_pair(vertex, x);
            return;
        }
        if(visited[x]!=1)
        {
            previous[x] = vertex;
            dfs(nodes, visited, ancestors, previous, x);
        }
    }
    ancestors.erase(ancestors.find(vertex));
    return;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // Possible if and only if the graph has a cycle;
    int n, m;
    cin>>n>>m;
    vector< vector<int>>nodes(n);
    set<pair<int, int>>s;
    for(int i = 0; i<m;i++)
    {
        int a, b;
        cin>>a>>b;
        if(s.find(make_pair(b,a))!= s.end())
        {
            cout<<"3\n" <<a<<" "<<b<<" "<<a<<endl;
            return 0;
        }
        s.insert(make_pair(a,b));
        nodes[a-1].push_back(b-1);
        // nodes[b-1].push_back(a-1);
    }
    vector<int>visited(n,0);
    vector<int>previous(n,-1);
    set<int> ancestors;
    for(int i = 0;i<n;i++)
    {
        if(cycle_node!=make_pair(-1,-1))
        {
            break;
        }
        if(visited[i]==0)
        {
            // cout<<"YES\n";
            dfs(nodes, visited, ancestors, previous, i);
        }
    }
    if(cycle_node == make_pair(-1,-1))
    {
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    int x = cycle_node.second;
    int vertex = cycle_node.first;
    vector<int>path;
    path.push_back(vertex+1);
    // for(auto p: previous)
    // {
    //     cout<<p<<" ";
    // }
    // cout<<"\n";
    // cout<<cycle_node.first<<" "<<cycle_node.second<<endl;
    while(vertex!=x)
    {
        // cout<<vertex<<endl;
        vertex = previous[vertex];
        path.push_back(vertex+1);
    }
    path.push_back(path[0]);
    cout<<path.size()<<endl;
    reverse(path.begin(), path.end());
    for(auto x: path)
    {
        cout<<x<<" ";
    }
    cout<<'\n';
    return 0;
} 
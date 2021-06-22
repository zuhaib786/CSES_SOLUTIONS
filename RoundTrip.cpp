#include<bits/stdc++.h>
#define MAX 1000000007
using namespace std;

pair<int,int> cycle_node = make_pair(-1,-1);
void dfs(vector<vector<int>>&nodes, vector<int> &previous, int node,vector<int>&visited)
{
    if(cycle_node!=make_pair(-1,-1))
    {
        return;
    }
    if(visited[node]==1)
    {
        return;
    }

    visited[node] = 1;
    for(auto x: nodes[node])
    {
        if(visited[x]==1 && previous[x]!=-1 && previous[node]!=x)
        {
            cycle_node = make_pair(x, node);
            return;
        }
        else if(visited[x]!=1)
        {
            
            previous[x] = node;
            dfs(nodes, previous, x, visited);
        } 
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // Possible if and only if the graph has a cycle;
    int n, m;
    cin>>n>>m;
    vector< vector<int>>nodes(n);
    for(int i = 0; i<m;i++)
    {
        int a, b;
        cin>>a>>b;
        nodes[a-1].push_back(b-1);
        nodes[b-1].push_back(a-1);
    }
    vector<int>visited(n, 0);
    vector<int>previous(n, -1);
    for(int i = 0;i<n;i++)
    {
        if(cycle_node!=make_pair(-1,-1))
        {
            break;
        }
        if(visited[i] == 0)
        {
            dfs(nodes, previous, i, visited);
        }
    }
 

    if(cycle_node == make_pair(-1,-1))
    {
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    else
    {
        vector<string>path;
        int cur = cycle_node.first;
        int count = 0;
        
        while(cur!=cycle_node.second)
        {
            path.push_back(to_string(cur+1));
            count++;
            
            if(cur == -1)
            {
                break;
            }
            cur = previous[cur];
        }
        cout<<count+2<<endl;
        for(auto x:path)
        {
            cout<<x<<" ";
        }
        cout<<to_string(cycle_node.second+1)<<" "<<path[0];
        cout<<endl;
    }
    return 0;
} 
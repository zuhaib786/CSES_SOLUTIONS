#include<bits/stdc++.h>
#define MAX 1000000007
using namespace std;
stack<int>order;

void dfs(vector< vector<int>>&nodes, vector<int>&visited, vector<int>&previous, int vertex)
{

    if(visited[vertex]==1)
    {
        return ;
    }
    // printSet(ancestors);
    // cout<<"Node: "<<vertex<<endl;
    visited[vertex] = 1;
    for(int x: nodes[vertex])
    {
     
        if(visited[x]!=1)
        {
            previous[x] = vertex;
            dfs(nodes, visited, previous, x);
        }
    }
    order.push(vertex);
    return;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // Possible if and only if the graph has a topological ordering, i.e. it is DAG;
    int n, m;
    cin>>n>>m;
    set<pair<int , int>>edges;
    vector< vector<int>>nodes(n);
    vector< vector<int>>rev_graph(n);
    for(int i = 0; i<m;i++)
    {
        int a, b;
        cin>>a>>b;
      
        nodes[a-1].push_back(b-1);
        edges.insert(make_pair(a-1, b-1));
        rev_graph[b-1].push_back(a-1);
    }
    vector<int>visited(n,0);
    vector<int>previous(n,-1);
    for(int i = 0;i<n;i++)
    {
       
        if(visited[i]==0)
        {
            dfs(nodes, visited, previous, i);
        }
    }
    vector<int>approachable(n,0);
    queue<int>q;
    q.push(n-1);
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        approachable[x] = 1;
        for(int w:rev_graph[x])
        {
            if(approachable[w]==0)
            {
                approachable[w] = 1;
                q.push(w);
            }
        }
    }
    vector<int>Topological_order;
    while(order.size()!=0)
    {
        Topological_order.push_back(order.top());
        order.pop();
    }
    if(approachable[0] == 0)
    {
        cout<<"IMPOSSIBLE\n";
    }
    else
    {
        vector<int> dist(n, -MAX);
        dist[0] = 0;
        vector<int>previous(n,-1);
        int cur = 0;
        while(Topological_order[cur]!=0)
        {
            cur++;
        }
        for(int i = cur; i<n;i++)
        {
            int u = Topological_order[i];
            // cout<<"u: "<<u<<"\n";
            // cout<<"[ ";
            for(int x: nodes[u])
            {
                // cout<<x<<" ";
                if(dist[x]< dist[u]+1)
                {
                    dist[x] = dist[u]+1;
                    previous[x] = u;
                }
            }
            // cout<<"] \n";
        }
        cout<<dist[n-1]+1<<endl;
        vector<int>path;
        path.push_back(n);
        cur = n-1;
        while(cur!=0)
        {
            cur = previous[cur];
            path.push_back(cur+1);
        }
        reverse(path.begin(), path.end());
        for(auto x:path)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
} 
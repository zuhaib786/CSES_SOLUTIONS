    #include<bits/stdc++.h>
    #define MAX 1000000007
    using namespace std; 
    stack<int>order;
    vector<vector<int>>connected_comp;
    int cur = -1;
    void dfs(vector<int>&visited, vector<vector<int>>&nodes, int vertex)
    {
        visited[vertex] = 1;
        for(auto x: nodes[vertex])
        {
            if(visited[x]==0)
            {
                visited[x] = 1;
                dfs(visited, nodes, x);
            }
        }
        order.push(vertex);
    }
    void rev_dfs(vector<int>&visited, vector<vector<int>>&nodes, int vertex)
    {
        visited[vertex] = 1;
        connected_comp[cur].push_back(vertex);
        for(auto x: nodes[vertex])
        {
            if(visited[x]==0)
            {
                visited[x] = 1;
                rev_dfs(visited, nodes, x);
            }
        }
        
    }
    int main()
    {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        // Strongly Connected Components.
        // Kosaraju's Algorithm
        int n,m;
        cin>>n>>m;
        vector<vector<int>>nodes(n);
        vector<vector<int>>rev_graph(n);
        for(int i = 0; i<m;i++)
        {
            int a, b;
            cin>>a>>b;
            nodes[a-1].push_back(b-1);
            rev_graph[b-1].push_back(a-1);
        }
        vector<int>visited(n,0);
        dfs(visited, nodes, 0);
        for(int i = 0; i<n;i++)
        {
            if(visited[i] == 0)
            {
                cout<<"NO\n"<<1<<" "<<i+1<<endl;
                return 0;
            }
        }
        vector<int>rev_visited(n,0);
        while(order.size()!=0)
        {
            int u = order.top();
            order.pop();
            if(rev_visited[u] == 0)
            {
                connected_comp.push_back(vector<int>());
                cur++;
                rev_dfs(rev_visited, rev_graph,u);
            }
        }
        if(cur==0)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
            cout<<connected_comp[1][0]+1<<" "<<connected_comp[0][0]+1<<endl;
        }
        return 0;
        

    }
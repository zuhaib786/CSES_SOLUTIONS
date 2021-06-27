    #include<bits/stdc++.h>
    #define MAX 1000000007
    using namespace std; 
    stack<int>order;
    vector<vector<int>>connected_comp;
    int cur = -1;
    void dfs(vector<int>&visited, vector<vector<int>>&nodes, int vertex)
    {

        if(visited[vertex] == 1)
            return;
        visited[vertex] = 1;
        for(auto x: nodes[vertex])
        {
            if(visited[x]==0)
            {
                visited[x] = 2;
                dfs(visited, nodes, x);
            }
        }
        order.push(vertex);
    }
    void rev_dfs(vector<int>&visited, vector<vector<int>>&nodes, int vertex)
    {
        if(visited[vertex] == 1)
            return ;
        visited[vertex] = 1;
        connected_comp[cur].push_back(vertex);
        for(auto x: nodes[vertex])
        {
            if(visited[x]==0)
            {
                visited[x] = 2;
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
        for(int i = 0; i<n;i++)
        {
            if(visited[i] == 0)
            {
                dfs(visited, nodes, i);
            }
        }
        vector<int>rev_visited(n,0);
        // cout<<"ORDER\n";
        while(order.size()!=0)
        {
            int u = order.top();
            // cout<<u<<" ";
            order.pop();
            if(rev_visited[u] == 0)
            {
                connected_comp.push_back(vector<int>());
                cur++;
                rev_dfs(rev_visited, rev_graph,u);
            }
        }
        // cout<<endl;
        map<int,int>mapping;
        int i = 0;
        for(auto vec: connected_comp)
        {
            i++;
            // cout<<"[ ";
            for(auto x: vec)
            {
                // cout<<x<<",";
                mapping[x] = i;
            }
            // cout<<"]\n";
        }
        cout<<connected_comp.size()<<endl;
        for(int i = 0;i<n;i++)
        {
            cout<<mapping[i]<<" ";
        }
        cout<<endl;
        return 0;
        

    }
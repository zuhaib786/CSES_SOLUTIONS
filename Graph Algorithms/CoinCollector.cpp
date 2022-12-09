    #include<bits/stdc++.h>
    #define MAX 1000000007
    using namespace std; 
    stack<int>order;
    vector<vector<int>>connected_comp;
    int cur = -1;
    long long int  value = 0;
    long long int max_count = 0;
    vector<int>coins;
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
    void FinalDFS(vector<int>&visited, vector<vector<int>>&nodes, int vertex)
    {
        if(visited[vertex] == 1)
            return;
        visited[vertex] = 1;
        value += coins[vertex];
        max_count = max(max_count, value);
        for(auto x: nodes[vertex])
        {
            if(visited[x]==0)
            {
                visited[x] = 2;
                FinalDFS(visited, nodes, x);
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
        coins = vector<int>(n,0);
        for(int i = 0 ; i<n ; i++)
        {
            cin>>coins[i];
        }
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
        vector<long long int>component_values(connected_comp.size()+1,0);
        map<int,int>mapping;
        for(int i = 0; i<connected_comp.size();i++)
        {
            for(int x: connected_comp[i])
            {
                mapping[x] = i+1;
                component_values[i+1]+=coins[x];
            }
        }
        set<pair<int, int>>edges;
        for(int i = 0; i<n;i++)
        {
            for(auto x: nodes[i])
            {
                edges.insert(make_pair(mapping[i], mapping[x]));
            }
        }
        vector<long long int>save = component_values;
        // for(auto x: save)
        // {
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        for(auto edge: edges)
        {
            int u = edge.first;
            int v = edge.second;
            // cout<<edge.first<<" "<<edge.second<<endl;
            if(u!=v)
                component_values[v] = max(component_values[v], component_values[u] + save[v]);
            // cout<<component_values[v]<<"\n";    
        }
        long long int max_count = component_values[0];
        for(int i = 0 ; i<component_values.size();i++)
        {
            max_count = max(max_count, component_values[i]);
        }
        cout<<max_count<<endl;
        return 0;
    }
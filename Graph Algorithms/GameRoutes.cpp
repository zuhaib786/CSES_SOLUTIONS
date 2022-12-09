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
        if(approachable[0] == 0)
        {
            cout<<0<<endl;
            return 0;
        }
        vector<int>Topological_order;
        while(order.size()!=0)
        {
            Topological_order.push_back(order.top());
            order.pop();
        }
        // for(auto x: Topological_order)
        // {
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        vector<long long int >paths(n, 0);
        paths[n-1] = 1;
        int cur = n-1;
        while(Topological_order[cur]!=n-1)
        {
            paths[Topological_order[cur]] = 0;
            cur--;
        }
        cur--;
        while(cur>=0)
        {
            int u = Topological_order[cur];
            // cout<<u<<" \n";
            for(auto x: nodes[u])
            {
                // cout<<x<<" ";
                paths[u] += paths[x];
                paths[u]%=MAX;
            }
            // cout<<endl;
            // cout<<endl;
            cur--;
        }    
        cout<<paths[0]<<endl;           

        return 0;
    } 
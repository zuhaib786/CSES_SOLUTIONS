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
    int getIndex(int a)
    {
        if(a<0)
        {
            a = -a;
            a--;
            return 2*a+1;
        }
        a--;
        return 2*a;
        
    }
    int main()
    {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        // Strongly Connected Components.
        // Kosaraju's Algorithm
        // 2-SAT
        // Assignment: 2*i for topping i inclusion 2*i+1 for topping i exclusion.
        int n,m;
        cin>>n>>m;
        vector<vector<int>>nodes(2*m);
        vector<vector<int>>rev_graph(2*m);
        for(int i = 0; i<n;i++)
        {
            string s1,s2;
            int a, b;
            cin>>s1>>a>>s2>>b;
            // cout<<s1<<" "<<s2<<" "<<a<<" "<<b<<endl;
           
            if(s1== "-")
            {
                a= -a;
            }
            if(s2 == "-")
            {
                b = -b;
            }
            // cout<<getIndex(a)<<" "<<getIndex(-a)<<" "<<getIndex(b)<<" "<<getIndex(-b)<<endl;

            nodes[getIndex(-a)].push_back(getIndex(b));
            nodes[getIndex(-b)].push_back(getIndex(a));
            rev_graph[getIndex(a)].push_back(getIndex(-b));
            rev_graph[getIndex(b)].push_back(getIndex(-a));
        }
        vector<int>visited(2*m,0);
        for(int i = 0; i<2*m;i++)
        {
            if(visited[i] == 0)
            {
                dfs(visited, nodes, i);
            }
        }
        vector<int>rev_visited(2*m,0);
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
        vector<bool>assignment(m);
        for(int i = 0; i<m;i++)
        {
            if(mapping[2*i] == mapping[2*i+1])
            {
                cout<<"IMPOSSIBLE\n";
                return 0;
            }
            else{
                assignment[i] = mapping[2*i]> mapping[2*i+1];
            }
        }
        for(int i = 0; i<m;i++)
        {
            if(assignment[i])
            {
                cout<<"+ ";
            }
            else
            {
                cout<<"- ";
            }
        }
        cout<<"\n";
        
        return 0;
        

    }
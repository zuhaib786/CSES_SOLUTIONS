    #include<bits/stdc++.h>
    #define MAX 1000000007
    using namespace std; 
    bool isConnected(vector<unordered_set<int>>&nodes, vector<int> & deg)
    {
        // cout<<"OKSSS\n";
        vector<bool> visited(nodes.size(), false);
        queue<int>q;
        q.push(0);
        while(q.size()!=0)
        {
            int u = q.front();
            q.pop();
            visited[u] = 1;
            for(int v: nodes[u])
            {
                if(visited[v]!=1)
                {
                    visited[v] = 1;
                    q.push(v);
                }
            }
        }
        for(int i = 0 ; i<nodes.size();i++)
        {
            if(deg[i]!=0 && visited[i]==0)
            {
                return false;
            }
        }
        // cout<<"Done\n";
        return true;
    }
    bool is_of_even_deg( vector<int> &deg)
    {
        int n = deg.size();
        for(int x: deg)
        {
            if(x%2 == 1)
            {
                if(x == n-1 || x== 0)
                {
                    continue;
                }
               
                return false;
            }
            else
            {
                if(x==n-1 || x== 0)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isPossible(vector<unordered_set<int>>&nodes, vector<int> &deg)
    {
        return isConnected(nodes, deg) && is_of_even_deg( deg);
    }
    int main()
    {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        cout.tie(NULL);
        // We need to find an Euler circuit of the graph.
        // Hierholzer’s algorithm
        int n, m;
        cin>>n>>m;
        vector<unordered_set<int>>nodes(n);
        vector<int>deg(n,0);
        for(int i = 0; i<m;i++)
        {
            int a, b;
            cin>>a>>b;
            nodes[a-1].insert(b-1);
            deg[a-1]++;
            deg[b-1]++;
        }
        if(!isPossible(nodes, deg))
        {
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
        nodes[n-1].insert(0);
        int v1 = 0;
        int v2 = n-1;
        stack<int>s;
        s.push(0);
        vector<int>res;
        // cout<<"WORKING BEGIN\n";
        // int num_itr = 1;
        while(!s.empty())
        {
            int v = s.top();
            if(nodes[v].size() == 0)
            {
                res.push_back(v);
                s.pop();
            }
            else
            {
                auto it = nodes[v].begin();
                int u = (*it);
                nodes[v].erase(nodes[v].begin());
                s.push(u);
            }
            // if(num_itr%100==0)
            // {
            //     cout<<"Number of itertaions = "<<num_itr<<endl;
            // }
            // num_itr++;
        }
        for(int i = 0 ;i<res.size()-1;i++)
        {
            if((res[i] == v1 && res[i+1] == v2)||(res[i] == v2 && res[i+1] == v1))
            {
                vector<int>res2;
                for(int j = i+1; j<res.size();j++)
                {
                    res2.push_back(res[j]);
                }
                for(int j = 1; j<=i; j++)
                {
                    res2.push_back(res[j]);
                }
                res = res2;
                break;
            }
        }
        if(res[0] == n-1)
        {
            reverse(res.begin(), res.end());
        }
        for(auto x: res)
        {
            cout<<x+1<<" ";
        }
        cout<<endl;
        return 0;
    }
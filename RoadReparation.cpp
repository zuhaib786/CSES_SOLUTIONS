    #include<bits/stdc++.h>
    #define MAX 1000000007
    using namespace std; 
    int Find(int x, vector<int> &parent)
    {
        while(x!=parent[x])
        {
            x = parent[x];
        }
        return x;
    }
    int Union(int x, int y, vector<int>&parent, vector<int>&rank)
    {
        x = Find(x, parent);
        y = Find(y, parent);
        if(rank[x]> rank[y])
        {
            parent[y] = x;
        }
        else if(rank[y]>rank[x])
        {
            parent[x]= y;
        }
        else
        {
            parent[y] = x;
            rank[x] +=1;
        }
    }
    
    int main()
    {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        // MST-> Kruskal Algorithm
        int n,m;
        cin>>n>>m;
        vector<int>parent(n);
        for(int i = 0;i<n;i++)
        {
            parent[i] = i;
        }
        vector<int>rank(n,0);
        vector<pair<int, pair<int, int>> >edges(m);
        int num_tree = n;
        for(int i = 0;i<m;i++)
        {
            cin>>edges[i].second.first>>edges[i].second.second>>edges[i].first;
            edges[i].second.first--;
            edges[i].second.second--;

        }
        sort(edges.begin(), edges.end());
        long long int cost = 0;
        for(auto edge:  edges)
        {
            int u = edge.second.first;
            int v = edge.second.second;
            int w = edge.first;
            u = Find(u,parent);
            v = Find(v, parent);
            if(u!=v)
            {
                cost+=w;
                Union(u, v, parent, rank);
                num_tree-=1;
            }
        }
        if(num_tree!=1)
        {
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
        cout<<cost<<endl;
        return 0;
        

    }
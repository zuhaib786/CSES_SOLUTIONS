    #include<bits/stdc++.h>
    #define MAX 1000000007
    using namespace std; 
    int maxSize = 1;
    int Find(int x, vector<int> &parent)
    {
        while(x!=parent[x])
        {
            x = parent[x];
        }
        return x;
    }
    void Union(int x, int y, vector<int>&parent, vector<int>&rank, vector<int>&size)
    {
        x = Find(x, parent);
        y = Find(y, parent);
        if(rank[x]> rank[y])
        {
            parent[y] = x;
            size[x]+=size[y];
            maxSize =  max(maxSize, size[x]);
        }
        else if(rank[y]>rank[x])
        {
            parent[x]= y;
            size[y]+=size[x];
            maxSize =  max(maxSize, size[y]);
        }
        else
        {
            parent[y] = x;
            rank[x] +=1;
            size[x]+=size[y];
            maxSize =  max(maxSize, size[x]);
        }
    }
    
    int main()
    {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        // Basic use of Union Find DS.

        int n,m;
        cin>>n>>m;
        vector<int>parent(n);
        for(int i = 0;i<n;i++)
        {
            parent[i] = i;
        }
        vector<int>rank(n,0);
        vector<int>size(n,1);
        vector<pair<int, int>>edges(m);
        int num_tree = n;
        for(int i = 0;i<m;i++)
        {
            cin>>edges[i].first>>edges[i].second;
            edges[i].first--;
            edges[i].second--;

        }
        for(auto edge:  edges)
        {
            int u = edge.first;
            int v = edge.second;
            u = Find(u,parent);
            v = Find(v, parent);
            if(u!=v)
            {
                Union(u, v, parent, rank,size);
                num_tree-=1;
            }
            cout<<num_tree<<" "<<maxSize<<endl;
        }
        return 0;
        

    }
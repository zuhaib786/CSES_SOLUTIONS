    #include<bits/stdc++.h>
    #define MAX 1000000007
    using namespace std; 
   
    
    int main()
    {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        // for each node we store The values of these four quantities.
        int n,m;
        cin>>n>>m;
        vector<vector<pair<int, int> > >nodes(n);
        for(int i = 0; i<m;i++)
        {
            int a, b,c ;
            cin>>a>>b>>c;
            nodes[a-1].push_back(make_pair(b-1,c));
        }
        vector<long long int>distance(n, MAX);
        vector<long long int>paths(n,0);
        vector<int>min_flights(n,-1);
        vector<int>max_flights(n,-1);
        distance[0] = 0;
        min_flights[0] = 0;
        max_flights[0] = 0;
        paths[0] = 1;
        set<pair<long long int, int> >s;
        s.insert(make_pair(0,0));
        while(!s.empty())
        {
            auto it = s.begin();
            long long int dist = (*it).first;
            int u = (*it).second;
            // cout<<" dist =  "<<dist<<" u =  "<<u<<endl;
            s.erase(it);
            for(auto p: nodes[u])
            {
                int v  = p.first;
                int c = p.second;
                if(distance[v] == MAX)
                {
                    distance[v] = distance[u]  + c;
                    paths[v] = paths[u];
                    min_flights[v] = min_flights[u]+1;
                    max_flights[v] = max_flights[u]+1;
                    s.insert(make_pair(distance[v], v));
                }
                else if(distance[v] == distance[u] + c)
                {
                    s.erase(s.find(make_pair(distance[v], v)));
                    paths[v] += paths[u];
                    paths[v]%=MAX;
                    min_flights[v] = min(min_flights[v], min_flights[u]+1);
                    max_flights[v] =  max(max_flights[v], max_flights[u] +1);
                    s.insert(make_pair(distance[v], v));
                }
                else if (distance[v] > distance[u]+c)
                {
                    s.erase(s.find(make_pair(distance[v], v)));
                    distance[v] = distance[u]+c;
                    paths[v] = paths[u];
                    min_flights[v] = min_flights[u]+1;
                    max_flights[v] =  max_flights[u] +1;
                    s.insert(make_pair(distance[v], v));
                }
            }
        }
        cout<<distance[n-1]<<" "<< paths[n-1]<<" "<<    min_flights[n-1]<<" "<< max_flights[n-1]<<endl;
        return 0;

    }
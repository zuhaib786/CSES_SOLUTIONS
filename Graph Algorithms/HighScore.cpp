#include<bits/stdc++.h>
#define MAX 1e14
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    //Bellman Ford
    pair<pair<int, int>, long long int> edges[m];
    vector<int> rev_graph[n];
    for(int i = 0;i<m;i++)
    {
        int a, b;
        long long int w;
        cin>>a>>b>>w;
        edges[i] = make_pair(make_pair(a-1, b-1), -w);
        rev_graph[b-1].push_back(a-1);
    }
    set<int>visited;
    visited.insert(n-1);
    queue<int>q;
    q.push(n-1);
    while(q.size()!=0)
    {
        int node = q.front();
        q.pop();
        visited.insert(node);
        for(int x: rev_graph[node])
        {
            if(visited.find(x) == visited.end())
            {
                q.push(x);
                visited.insert(x);
            }
        }
    }
    // cout<<"Rev DFS COmp\n"<<'\n';
    long long int distance[n];
    fill(distance, distance + n, MAX);
    distance[0] = 0;
    for(int i = 1; i<n;i++)
    {
        for(int j = 0; j<m; j++)
        {
            pair<pair<int, int>, long long int> p = edges[j];
            int u, v;
            long long int w;
            u = p.first.first;
            v = p.first.second;
            w = p.second;
            if(distance[u] != MAX)
            {
                if(distance[v] == MAX)
                {
                    distance[v] = distance[u] + w;
                }
                else if(distance[v] > distance[u] + w)
                {
                    distance[v] = distance[u] + w;
                }
            }
        }
    }
    for(int j = 0; j<m; j++)
    {
        pair<pair<int, int>, long long int> p = edges[j];
        int u, v;
        long long int w;
        u = p.first.first;
        v = p.first.second;
        w = p.second;
        if(distance[u] != MAX)
        {
            if(distance[v] == MAX)
            {
                if(visited.find(v)!= visited.end())
                {
                    cout<<-1<<endl;
                    return 0;
                }
                
            }
            else if(distance[v] > distance[u] + w)
            {
                
                if(visited.find(v)!= visited.end())
                {
                    cout<<-1<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<-1*distance[n-1]<<endl;
    return 0;
} 
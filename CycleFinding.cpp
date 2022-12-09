#include<bits/stdc++.h>
#define MAX 1e18+7
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    //Bellman Ford
    vector<pair<pair<int, int>, long long int>> edges(m);
    for(int i = 0;i<m;i++)
    {
        int a, b;
        long long int w;
        cin>>a>>b>>w;
        edges[i] = make_pair(make_pair(a-1, b-1), w);
    }
    vector<long long int>distance(n,0);
    distance[0] = 0;
    vector<int> previous(n, -1);
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
                    previous[v] = u;
                }
                else if(distance[v] > distance[u] + w)
                {
                    distance[v] = distance[u] + w;
                    previous[v] = u;
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
                previous[v] = u;
                cout<<"YES"<<endl;
                vector<string> path ;
                path.push_back(to_string(v+1));
                int x = previous[v] ;
                set<int>visited;
                visited.insert(v+1);
                while(true)
                {
                    path.push_back(to_string(x+1));
                    if(visited.find(x+1)!= visited.end())
                    {
                        break;

                    }
                    visited.insert(x+1);
                    x = previous[x];
                }
                reverse(path.begin(), path.end());
                for(int i = 0 ; i<path.size();i++)
                {
                    if(i!=0 &&path[i] == path[0])
                    {
                        cout<<path[i];
                        break;
                    }
                    cout<<path[i]<<" ";
                }
                cout<<endl;
                return 0;
            }
            else if(distance[v] > distance[u] + w)
            {
                previous[v] = u;
                cout<<"YES"<<endl;
                vector<string> path ;
                path.push_back(to_string(v+1));
                int x = previous[v] ;
                set<int>visited;
                visited.insert(v+1);
                while(true)
                {
                    path.push_back(to_string(x+1));
                    if(visited.find(x+1)!= visited.end())
                    {
                        break;

                    }
                    visited.insert(x+1);
                    x = previous[x];
                }
                reverse(path.begin(), path.end());
                for(int i = 0 ; i<path.size();i++)
                {
                    if(i!=0 &&path[i] == path[0])
                    {
                        cout<<path[i];
                        break;
                    }
                    cout<<path[i]<<" ";
                }
                cout<<endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
} 
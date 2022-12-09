#include<bits/stdc++.h>
#define MAX 1e18+7
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    vector<vector<pair<int, int>> >nodes(n);
    for(int i = 0; i<m;i++)
    {
        int a, b, w;
        cin>>a>>b>>w;
        nodes[a-1].emplace_back(b-1, w);
    }
    vector<vector<long long int>>distance(n, vector<long long int>(2,MAX));
    distance[0][0] = 0;
    distance[0][1] = 0;
    set<pair<long long int, int>>s;
    s.insert(make_pair(0,0));
    while(s.size()!=0)
    {
        pair<long long int,int>p = (*s.begin());
        s.erase(s.begin());
        
        int node = p.second;
        for(auto x: nodes[node])
        {
            if(p.first + x.second < distance[x.first][0])
            {
                if(s.find(make_pair(distance[x.first][0], x.first)) == s.end())
                {
                    distance[x.first][0] = p.first + x.second;
                    s.insert(make_pair(distance[x.first][0], x.first));
                }
                else
                {
                    s.erase(s.find(make_pair(distance[x.first][0], x.first)));
                    distance[x.first][0] = p.first + x.second;
                    s.insert(make_pair(distance[x.first][0], x.first));
                }
                
            }
        }
    }
    s.clear();
    s.insert(make_pair(0,0));
    set<int> visited;
    while(s.size()!=0)
    {
        pair<long long int,int>p = (*s.begin());
        s.erase(s.begin());
       
        int node = p.second;
        if(visited.find(node) != visited.end())
            continue;
        visited.insert(node);
        for(auto x: nodes[node])
        {
            if(visited.find(x.first) == visited.end())
            {
                if(s.find(make_pair(distance[x.first][1], x.first))!= s.end())
                    s.erase(s.find(make_pair(distance[x.first][1], x.first)));
                distance[x.first][1] = min(distance[x.first][1],min(p.first + x.second,distance[node][0]+x.second/2));// main Step
                s.insert(make_pair(distance[x.first][1], x.first));
            }
        }
    }
    cout<<distance[n-1][1]<<endl;
    return 0;
} 
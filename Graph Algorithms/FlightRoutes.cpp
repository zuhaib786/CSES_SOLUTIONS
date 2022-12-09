#include<bits/stdc++.h>
#define MAX 1e18+7
using namespace std;
void Dijkstra(vector<vector<pair<int, int>>>&nodes, vector<vector<long long int>>&distance, int k)
{
    priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<pair<long long int, int> > >q;
    q.push(make_pair(0,0));
    
    while(q.size()!=0)
    {
        pair<long long int, int>p = q.top();
        q.pop();
        int node = p.second;
        long long int dist = p.first;
        if(distance[node][k-1]<dist)
        {
            continue;
        }
        for(auto x: nodes[node])
        {
            if(distance[x.first][k-1]> dist + x.second)
            {
                distance[x.first][k-1] = x.second+dist;
                q.push(make_pair(distance[x.first][k-1], x.first) );
                sort(distance[x.first].begin(), distance[x.first].end());
            }
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, k;
    cin>>n>>m>>k;
    vector<vector<pair<int, int>>>nodes(n);
    for(int i = 0; i<m;i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        nodes[a-1].push_back(make_pair(b-1, c));
    }
    vector<vector<long long int>>distance(n, vector<long long int>(k,MAX));
    distance[0][0] = 0;
    Dijkstra(nodes, distance, k);
    for(auto x: distance[n-1])
    {
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
} 
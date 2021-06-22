#include<bits/stdc++.h>
#define MAX 1000000007
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    vector<vector<pair<int, int>>>nodes(n);
    for(int i = 0;i<m;i++)
    {
        int a, b, w;
        cin>>a>>b>>w;
        nodes[a-1].emplace_back(b-1, w);
    }
    set<pair<long long int, int>>s;// min-heap
    s.insert(make_pair(0,0));
    vector<long long int>distance(n, 1e18+7 );
    distance[0] = 0;
    while(s.size()!=0)
    {
        pair<long long int,int>p = (*s.begin());
        s.erase(s.begin());
        
        int node = p.second;
        for(auto x: nodes[node])
        {
            if(p.first + x.second < distance[x.first])
            {
                if(s.find(make_pair(distance[x.first], x.first)) == s.end())
                {
                    distance[x.first] = p.first + x.second;
                    s.insert(make_pair(distance[x.first], x.first));
                }
                else
                {
                    s.erase(s.find(make_pair(distance[x.first], x.first)));
                    distance[x.first] = p.first + x.second;
                    s.insert(make_pair(distance[x.first], x.first));
                }
                
            }
        }
    }
    for(int i=0 ; i<n;i++)
    {
        cout<<distance[i]<<" ";
    }
    cout<<endl;
    
    return 0;
} 
#include<bits/stdc++.h>
#define MAX 1000000007
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m,q;
    cin>>n>>m>>q;
    // vector<vector<pair<int, int>>>nodes(n);
    vector<vector<long long int>>distance(n, vector<long long int>(n,-1));
    for(int i =0; i<n;i++)
    {
        distance[i][i] = 0;
    }
    for(int i = 0;i<m;i++)
    {
        int a, b;
        long long int w;
        cin>>a>>b>>w;
        if(distance[a-1][b-1] == -1)
            distance[a-1][b-1] = w;
        else
           distance[a-1][b-1] = min( w,distance[a-1][b-1] );    
        if(distance[b-1][a-1] == -1)
            distance[b-1][a-1] = w;
        else
           distance[b-1][a-1] = min( w,distance[b-1][a-1] ); 
        // nodes[a-1].emplace_back(b-1, w);
        // nodes[b-1].emplace_back(a-1, w);
    } 
    for(int k = 0; k<n;k++)
    {
        for(int i = 0; i<n;i++)
        {
            for(int j = 0; j<n;j++)
            {
                if(distance[i][k]!=-1 && distance[k][j]!=-1)
                {
                    if(distance[i][j] == -1 )
                    {
                        distance[i][j] = distance[i][k] + distance[k][j];
                    }
                    else if(distance[i][j]> distance[i][k] + distance[k][j])
                    {
                        distance[i][j] = distance[i][k] + distance[k][j];
                    } 
                }
                
            }
        }
    }  
    for(int i = 0;i<q;i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<distance[x-1][y-1]<<endl;
    }
    
    return 0;
} 
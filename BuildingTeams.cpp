#include<bits/stdc++.h>
#define MAX 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // Possible if and only if the graph is bipartite;
    int n, m;
    cin>>n>>m;
    vector< vector<int>>nodes(n);
    for(int i = 0; i<m;i++)
    {
        int a, b;
        cin>>a>>b;
        nodes[a-1].push_back(b-1);
        nodes[b-1].push_back(a-1);
    }
    bool bipartite = true;
    vector<int>coloring(n,-1);
    for(int i = 0; i<n;i++)
    {
        if(!bipartite)
        {
            break;
        }
        if(coloring[i] == -1)
        {
            coloring[i] = 0;
            stack<int>s;
            s.push(i);
            while(s.size()!=0)
            {
                int node = s.top();
                s.pop();
                for(int x: nodes[node])
                {
                    if(coloring[x] == coloring[node])
                    {
                        bipartite = false;
                        break;
                    }
                    else if(coloring[x] == -1)
                    {
                        coloring[x] = (coloring[node]^1);
                        s.push(x);
                    }
                }
            }
        }
    }
    if(!bipartite)
    {
        cout<<"IMPOSSIBLE\n";
    }
    else
    {
        for(int i = 0;i<n;i++)
        {
            cout<<coloring[i]+1<<' ';
        }
        cout<<endl;
    }
    return 0;
} 
#include<bits/stdc++.h>
#define MAX 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    vector<vector<int>>nodes(n);
    for(int i =0;i<m;i++)
    {
        int a, b;
        cin>>a>>b;
        nodes[a-1].push_back(b-1);
        nodes[b-1].push_back(a-1);
    }
    int visited[n] = {0};
    vector<int> previous(n, -1);
    queue<int>q;
    q.push(0);
    while(q.size()!=0)
    {
        int node = q.front();
        q.pop();
        // cout<<node<<endl;
        if (node == n-1)
        {
            visited[node] = 1;
            break;
        }
        else if (visited[node] == 1)
        {
            continue;
        }
        else
        {
            visited[node] = 1;
            for(int x: nodes[node])
            {
                if(visited[x] == 1)
                {
                    continue;
                }
                else
                {
                    q.push(x);
                    if (previous[x] == -1)
                        previous[x] = node;
                }
            }
        }
    }
    // for(int x: previous)
    // {
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    if(visited[n-1] == 0)
    {
        cout<<"IMPOSSIBLE\n";
    }
    else
    {
        vector<string>path;
        int cur = n-1;
        int count = 1;
        path.push_back(to_string(cur+1));
        while(cur!=0)
        {
           cur = previous[cur];
           count++;
           path.push_back(to_string(cur+1));
        }
        reverse(path.begin(), path.end());
        string ans = "";
        for(int i = 0;i<path.size()-1;i++)
        {
            ans+=path[i]+' ';
        }
        ans+=path[path.size()-1];
        cout<<count<<'\n'<<ans<<endl;
    }
    return 0;
}   

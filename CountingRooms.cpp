#include<bits/stdc++.h>
#define MAX 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // Number of Connected components.
    int n, m;
    cin>>n>>m;
    vector<string>v(n);
    for(int i = 0; i<n;i++)
    {
        cin>>v[i];
    }
    vector<vector<bool>>visited(n, vector<bool>(m,false));
    int count = 0;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0; j<m;j++)
        {
            // cout<<v[i][j];
            if(v[i][j] == '#' || visited[i][j] == true)
            {
                // cout<<"YES "<<v[i][j]<<" "<<visited[i][j]<<'\n';
                visited[i][j] = true;
            }
            else
            {
                // cout<<i<<" "<<j<<endl;
                count++;
                stack<pair<int, int>>s;
                s.push(make_pair(i,j));
                while(s.size()!=0)
                {
                    pair<int, int>p = s.top();
                    s.pop();
                    if(v[p.first][p.second] == '#'||visited[p.first][p.second] ==true )
                    {
                        continue;
                    }
                    visited[p.first][p.second] = true;
                    if(p.first>0)
                    {
                        s.push(make_pair(p.first-1, p.second));
                    }
                    if(p.first<n-1)
                    {
                        s.push(make_pair(p.first+1, p.second));
                    }
                    if(p.second>0)
                    {
                        s.push(make_pair(p.first, p.second-1));
                    }
                    if(p.second<m-1)
                    {
                        s.push(make_pair(p.first, p.second+1));
                    }
                }
            }
        }
        // cout<<endl;
    }
    cout<<count<<endl;
    return 0;
}   

#include<bits/stdc++.h>
#define MAX 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    vector<string>v(n);
    pair<int, int> start, end;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for(int i = 0; i<n;i++)
    {
        cin>>v[i];
        for(int j=0;j<m;j++)
        {
            if(v[i][j] == 'A')
            {
                start = make_pair(i,j);
            }
            else if (v[i][j] == 'B')
            {
                end = make_pair(i, j);
            }
            else if(v[i][j] == '#')
            {
                visited[i][j] = true;
            }
        }
    }
    queue<pair<int, int>> q ;
    q.push(start);
    map<pair<int, int>, pair<int,int >>previous;
    while(q.size()!=0)
    {
        pair<int,int>p = q.front();
        q.pop();
        if(p == end)
        {
            visited[end.first][end.second] = true;
            break;
        }
        else if (visited[p.first][p.second])
        {
            continue;
        }
        else
        {
            visited[p.first][p.second] = true;
            if(p.first>0&&v[p.first-1][p.second]!='#'&& !visited[p.first-1][p.second])
            {
                q.push(make_pair(p.first-1, p.second)); 
                previous[make_pair(p.first-1, p.second)] = p;               
            }
            if (p.first<n-1&& v[p.first+1][p.second]!='#'&&!visited[p.first+1][p.second])
            {
                q.push(make_pair(p.first+1, p.second));
                previous[make_pair(p.first+1, p.second)] = p; 
            }

            if(p.second>0&&v[p.first][p.second-1]!='#'&& !visited[p.first][p.second-1])
            {
                q.push(make_pair(p.first, p.second-1));   
                previous[make_pair(p.first, p.second-1)] = p;              
            }
            if (p.second<m-1&& v[p.first][p.second+1]!='#'&& !visited[p.first][p.second+1])
            {
                q.push(make_pair(p.first, p.second+1));
                previous[make_pair(p.first, p.second+1)] = p;
            }
        }
    }
    if(!visited[end.first][end.second])
    {
        cout<<"NO\n";
    }
    else
    {
        string path = "";
        pair<int, int> cur = end;
        while(cur!=start)
        {
            pair<int, int> temp = previous[cur];
            if(temp.first+1 == cur.first)
            {
                path+='D';
            }
            else if (temp.first-1 == cur.first)
            {
                path+='U';
            }
            else if (temp.second+1 == cur.second)
            {
                path+='R';
            }
            else if (temp.second-1 == cur.second)
            {
                path+='L';
            }
            else
            {
                cout<<"error\n";
                return 0;
            }
            cur = temp;
        }
        reverse(path.begin(), path.end());
        cout<<"YES\n"<< path.size() << "\n" <<path<<endl;
    }
    
    return 0;
}   

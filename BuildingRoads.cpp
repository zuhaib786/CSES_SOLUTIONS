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
    vector<vector<int>>connected_components;
    int count = 0;
    for(int i = 0;i<n;i++)
    {
        if(visited[i] == 0)
        {
            count++;
            stack<int>s;
            s.push(i);
            vector<int>temp(1);
            temp[0] = i;
            connected_components.push_back(temp);
            while(s.size()!=0)
            {
                int node = s.top();
                s.pop();
                if(visited[node]==1)
                {
                    continue;
                }
                connected_components[count-1].push_back(node);
                visited[node] = 1;
                for(int x: nodes[node])
                {
                    if(visited[x] == 0)
                    {
                        s.push(x);
                    }
                }
            }
        }
    }
    string paths = "";
    for(int i =0; i<connected_components.size()-1;i++)
    {
        paths+= to_string(connected_components[i][0]+1)+" "+to_string(connected_components[i+1][0]+1)+'\n';
    }
    if(connected_components.size()==1)
    {
        cout<<0<<endl;
        return 0;
    }
    else
    {
        cout<<connected_components.size()-1<<"\n"<<paths;
    }
    return 0;
}   

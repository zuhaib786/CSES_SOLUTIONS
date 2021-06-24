#include<bits/stdc++.h>
#define MAX 1000000007
using namespace std;

void dfs(vector< vector<int>>&nodes, vector<int>&visited, set<int> ancestors, vector<int>&previous, int vertex)
{
    visited[vertex] = 1;
    for(int x: nodes[vertex])
    {
        
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // Possible if and only if the graph has a cycle;
    int n, m;
    cin>>n>>m;
    vector< vector<int>>nodes(n);
    set<pair<int, int>>s;
    for(int i = 0; i<m;i++)
    {
        int a, b;
        cin>>a>>b;
        if(s.find(make_pair(b,a))!= s.end())
        {
            cout<<"3\n" <<a<<" "<<b<<" "<<a<<endl;
            return 0;
        }
        s.insert(make_pair(a,b));
        nodes[a-1].push_back(b-1);
        // nodes[b-1].push_back(a-1);
    }
    return 0;
} 
#include<bits/stdc++.h>
#define MAX 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> start(n), end(n), earning(n);
    set<int>s;
    for(int i = 0; i<n;i++)
    {
        cin>>start[i]>>end[i]>>earning[i];
        end[i]+=1;
        s.insert(start[i]);
        s.insert(end[i]);
    }
    int count = 0;
    map<int, int> m;
    for(auto i: s)
    {
        m[i] = count;
        count++;
    }
    vector<long long int>dp(count, 0);
    vector< vector<pair<int,int>>>projects(count);
    for(int i = 0; i<n;i++)
    {
        int index = m[end[i]];
        projects[index].push_back(make_pair(m[start[i]], earning[i]));// projects ending at index i;

    }
    for(int i = 0;i<count;i++)
    {
        if(i!=0)
        {
            dp[i] = dp[i-1];
        }
        for(auto p: projects[i])
        {
            dp[i] = max(dp[i], dp[p.first]+p.second);
        }
    }
    cout<<dp[count-1]<<endl;
    return 0;
}   

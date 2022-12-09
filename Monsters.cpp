#include<bits/stdc++.h>
#define MAX 1000000007
using namespace std;

void MultisourceBFS(vector<string>&v, vector<pair<int, int>>&monsters, pair<int,int> source, vector<vector<pair<int,int>>> &distance)
{
    int n = v.size();
    int m  = v[0].size();
    queue< pair < pair<int,int> , pair<int, int>>>q;
    for(int i = 0; i<monsters.size();i++)
    {
        distance[monsters[i].first][monsters[i].second].second = 0;
        q.push(make_pair(monsters[i], make_pair(0,1)));
    }
    distance[source.first][source.second].first =0;  
    q.push(make_pair(source, make_pair(0,0)));
    while(q.size()!=0)
    {
       pair < pair<int,int> , pair<int, int>> p = q.front();
       q.pop();
       pair<int,int>coords = p.first;
       pair<int,int>dist_iden = p.second;
       if(dist_iden.second == 1)
       {
           // Monster
           if(coords.first>0 && v[coords.first-1][coords.second]!='#'&& distance[coords.first-1][coords.second].second==-1)
           {
               q.push(make_pair(make_pair(coords.first-1,coords.second), make_pair(dist_iden.first+1, dist_iden.second)));
               distance[coords.first-1][coords.second].second = dist_iden.first+1;
           }

           if(coords.first<n-1 && v[coords.first+1][coords.second]!='#'&& distance[coords.first+1][coords.second].second==-1)
           {
               q.push(make_pair(make_pair(coords.first+1,coords.second), make_pair(dist_iden.first+1, dist_iden.second)));
               distance[coords.first+1][coords.second].second = dist_iden.first+1;
           }

           if(coords.second>0 && v[coords.first][coords.second-1]!='#'&& distance[coords.first][coords.second-1].second==-1)
           {
               q.push(make_pair(make_pair(coords.first,coords.second-1), make_pair(dist_iden.first+1, dist_iden.second)));
               distance[coords.first][coords.second-1].second = dist_iden.first+1;
           }

           if(coords.second<m-1 && v[coords.first][coords.second+1]!='#'&& distance[coords.first][coords.second+1].second==-1)
           {
               q.push(make_pair(make_pair(coords.first,coords.second+1), make_pair(dist_iden.first+1, dist_iden.second)));
               distance[coords.first][coords.second+1].second = dist_iden.first+1;
           }
       }
       else
       {
           // Person
           if(coords.first>0 && v[coords.first-1][coords.second]!='#'&& distance[coords.first-1][coords.second].first==-1)
           {
               q.push(make_pair(make_pair(coords.first-1,coords.second), make_pair(dist_iden.first+1, dist_iden.second)));
               distance[coords.first-1][coords.second].first = dist_iden.first+1;
           }

           if(coords.first<n-1 && v[coords.first+1][coords.second]!='#'&& distance[coords.first+1][coords.second].first==-1)
           {
               q.push(make_pair(make_pair(coords.first+1,coords.second), make_pair(dist_iden.first+1, dist_iden.second)));
               distance[coords.first+1][coords.second].first = dist_iden.first+1;
           }

           if(coords.second>0 && v[coords.first][coords.second-1]!='#'&& distance[coords.first][coords.second-1].first==-1)
           {
               q.push(make_pair(make_pair(coords.first,coords.second-1), make_pair(dist_iden.first+1, dist_iden.second)));
               distance[coords.first][coords.second-1].first = dist_iden.first+1;
           }

           if(coords.second<m-1 && v[coords.first][coords.second+1]!='#'&& distance[coords.first][coords.second+1].first==-1)
           {
               q.push(make_pair(make_pair(coords.first,coords.second+1), make_pair(dist_iden.first+1, dist_iden.second)));
               distance[coords.first][coords.second+1].first = dist_iden.first+1;
           }
       }  
    } 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    vector<string>v(n);
    vector<pair<int, int>>monsters ;
    pair<int, int>start ;
    vector<pair<int, int> > candidates;
    for(int i = 0;i<n;i++)
    {
        cin>>v[i];
        for(int j = 0;j<m;j++)
        {
            if(v[i][j] == 'M')
            {
                monsters.emplace_back(i,j);
            }
            else if(v[i][j]=='A')
            {
                start = make_pair(i,j);
                if(i==n-1|| j==m-1)
                {
                    candidates.push_back(make_pair(i,j));
                }
            }
            else if (v[i][j] == '.')
            {
                if(i==n-1|| j==m-1||i == 0|| j == 0)
                {
                    candidates.push_back(make_pair(i,j));
                }
            }
        }
    }    
    if(candidates.size()==0)
    {
        cout<<"NO\n";
        return 0;
    }
    vector<vector<pair<int,int>> >distance(n, vector<pair<int, int>>(m, make_pair(-1,-1)));
    MultisourceBFS(v, monsters, start, distance);
    pair<int, int>ans = make_pair(-1, -1);
    for(auto candidate: candidates)
    {
        if(distance[candidate.first][candidate.second].first!=-1 && (distance[candidate.first][candidate.second].first < distance[candidate.first][candidate.second].second ||distance[candidate.first][candidate.second].second==-1) )
        {
            ans = candidate;
            break;
        }
    }
    // for(auto vec: distance)
    // {
    //     for(auto p: vec)
    //     {
    //         cout<<p.first<<" ";
    //     }
    //     cout<<endl;
    // }
    if(ans.first == -1)
    {
        cout<<"NO\n";
        return 0;
    }
    else
    {
        cout<<"YES\n";
        // Reconstruct Path;
        // cout<<ans.first<<" "<<ans.second<<endl;
        string path = "";
        int count = 0;
        while(ans!=start)
        {
            // pair<int, int>temp;
            // cout<<ans.first<<" "<<ans.second<<endl;
            if(ans.first>0)
            {
                
                if(v[ans.first-1][ans.second]!='#'&&distance[ans.first-1][ans.second].first+1== distance[ans.first][ans.second].first)
                {
                    // cout<<"YES1\n";
                    ans = make_pair(ans.first-1, ans.second);
                    path+='D';
                    count++;
                    continue;
                }
                
                
            }
            if(ans.first<n-1)
            {
                
                if(v[ans.first+1][ans.second]!='#'&&distance[ans.first+1][ans.second].first+1== distance[ans.first][ans.second].first)
                {
                    // cout<<"YES2\n";
                    ans = make_pair(ans.first+1, ans.second);
                    path+='U';
                    count++;
                    continue;
                }
                
            }
            if(ans.second>0)
            {
                
                if(v[ans.first][ans.second-1]!='#'&&distance[ans.first][ans.second-1].first+1== distance[ans.first][ans.second].first)
                {
                    // cout<<"YES3\n";
                    ans = make_pair(ans.first, ans.second-1);
                    path+='R';
                    count++;
                    continue;
                }
                
            }
            if(ans.second<m-1)
            {
                
                if(v[ans.first][ans.second+1]!='#'&&distance[ans.first][ans.second+1].first+1== distance[ans.first][ans.second].first)
                {
                    // cout<<"YES4\n";
                    ans = make_pair(ans.first, ans.second+1);
                    path+='L';
                    count++;
                    continue;
                }
                
            }
            
        }
        reverse(path.begin(), path.end());
        cout<<count<<"\n"<<path<<'\n';
    }
    return 0;
} 
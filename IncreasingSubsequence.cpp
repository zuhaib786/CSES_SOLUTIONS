#include<bits/stdc++.h>
#define MAX 1000000007
using namespace std;
void print_set(set<pair<int, int>> &s)
{
    for(auto i:s)
    {
        cout<< "[ " <<i.first<<", "<<i.second<<"] ";
    }
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    set<pair<int, int>>s;
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i = 0; i<n;i++)
    {
        cin>>v[i];
    }
    for(int i = 0; i<n ;i++)
    {
        if (s.size() == 0)
        {
            s.insert(make_pair(v[i],1));
        }
        else
        {
            auto it = s.begin();
            if ((*it).first > v[i])
            {
                if  ((*it).second ==1)
                {
                    s.erase(it);
                }
                s.insert(make_pair(v[i], 1));
            }
            else
            {
                auto it = s.upper_bound(make_pair(v[i], 0));
                if(it == s.end())
                {
                    it--;
                    s.insert(make_pair(v[i], (*it).second+1));
                }
                else
                {
                    if(it == s.begin())
                    {
                        continue;
                    }
                    else
                    {
                        it--;
                        int length = it->second +1;
                        s.insert(make_pair(v[i],it->second +1));
                        it = s.find(make_pair(v[i],it->second +1));
                        
                        it++;
                        // cout<<it->second<<" "<<length<<" secnd\n";
                        if(it->second == length)
                        {
                            s.erase(it);
                        }
                    }
                }

            }
        }
        // print_set(s);
    }
    int length = 0;
    for(auto i:s)
    {
        length = max(length, i.second);
    }
    cout<<length<<endl;
    return 0;
}   

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000007
// Segment Tree.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<int,int> , null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
int main()
    {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        cout.tie(NULL);
        int n,q;
        cin>>n>>q;
        ordered_set s;
        vector<int>v(n,0);
        for(int i = 0;i<n;i++)
        {
            cin>>v[i];
            s.insert(make_pair(v[i],i));
        }
        for(int i = 0 ; i<q;i++)
        {
            string k;
            cin>>k;
            if(k=="!")
            {
                int a,b;
                cin>>a>>b;
                a--;

                s.erase(s.find(make_pair(v[a],a)));
                v[a] = b;
                s.insert(make_pair(v[a],a));
            }
            else
            {
                int a, b;
                cin>>a>>b;
                int x = s.order_of_key(make_pair(a,-1));
                int y = s.order_of_key(make_pair(b,n));
                cout<<y-x<<"\n";    
            }
        }
        return 0;
    }
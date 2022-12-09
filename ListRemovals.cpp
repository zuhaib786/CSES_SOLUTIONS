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
        int n;
        cin>>n;
        ordered_set s;
        for(int i = 0 ; i<n;i++)
        {
            int a;
            cin>>a;
            s.insert(make_pair(i,a));

        }
        for(int i = 0; i<n;i++)
        {
            int order;
            cin>>order;
            order--;
            auto it = s.find_by_order(order);
            cout<<(*it).second<<" ";
            s.erase(it);
        }
        cout<<endl;
        return 0;
    }
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int> >, rb_tree_tag,tree_order_statistics_node_update>
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  ordered_set window;
  int n,k;
  cin>>n>>k;
  vector<int>v(n);
  for(int i = 0;i<n;i++)
  {
    cin>>v[i];
  }
  if (k==1)
  {
    for(int i = 0;i<n;i++)
    {
      cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
  }
  for(int i = 0;i<k-1;i++)
  {
    window.insert(make_pair(v[i], i));
  }
  for(int i = k-1;i<n;i++)
  {
      window.insert(make_pair(v[i], i));
      auto it = window.find_by_order((k-1)/2);
      cout<<(*it).first<<" ";
      window.erase(window.find(make_pair(v[i-k+1], i-k+1)));
  }
  cout<<endl;
  return 0;
  
}
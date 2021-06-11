#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int main() {
  ordered_set children;
  int n,k;
  cin>>n>>k;
  for(int i = 1;i<n+1;i++)
  {
    children.insert(i);
  } 
  int cur_pos = 0;
  while (children.size()!=0)
  {
    int pos = (cur_pos+k)%children.size();
    cur_pos = pos;
    auto it = children.find_by_order(cur_pos);
    cout<<*it<<" ";
    children.erase(it);
  }
  cout<<"\n";
  return 0;
}
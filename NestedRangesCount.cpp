#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
  
#define ordered_set tree<pair<int, int> , null_type,less<pair<int, int> >, rb_tree_tag,tree_order_statistics_node_update>
struct range
{
  int first;
  int second;
  int index;
};
bool compare(range range1, range range2)
{
  if (range1.first== range2.first)
  {
    return range1.second > range2.second;
  }
  return range1.first < range2.first;
}

int main() {
  int n;
  cin>>n;
  ordered_set contains_set;
  ordered_set is_contained_set;
  vector<range> v(n);
  vector<int> contains(n, 0);
  vector<int> is_contained(n, 0);
  for(int i = 0; i<n;i++)
  {
    int a, b;
    cin>>a>>b;
    v[i] = {a, b, i};
  }
  sort(v.begin(), v.end(), compare);
  // for(auto i: v)
  // {
  //   cout<< i.first<< " "<< i.second<< ", ";
  // }
  // cout<<endl;
  int i = 0, j = n-1;
  for(; i<n && j>=0; i++, j--)
  {
    range r1 = v[i];
    range r2 = v[j];
    is_contained_set.insert(make_pair(r1.second, - i));
    int order = is_contained_set.order_of_key(make_pair(r1.second, -i));
    is_contained[r1.index] = i - order;
    contains_set.insert(make_pair(r2.second, -j));
    order = contains_set.order_of_key(make_pair(r2.second, -j));
    contains[r2.index] = order;
  }
  for(int i = 0; i<n;i++)
  {
    cout<< contains[i]<<" ";
  }
  cout<<endl;
  for(int i = 0; i<n;i++)
  {
    cout<< is_contained[i]<<" ";
  }
  cout<<endl;
  return 0;
}
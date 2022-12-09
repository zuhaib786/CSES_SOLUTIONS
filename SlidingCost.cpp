#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int> >, rb_tree_tag,tree_order_statistics_node_update>

void update(vector<long long int>&v, vector<long long int>&fenwick_tree, int index, int val)
{
  index++;
  while(index<=v.size())
  {
    fenwick_tree[index]+=val;
    index += index&(-index);// Get next
  }
}
long long  getSum(vector<long long int> &fenwick_tree, int index)
{
  index ++;
  long long int sum = 0;
  while (index>0)
  {
    sum+= fenwick_tree[index];
    index -= index &(-index);// Get parent;
  }
  return sum;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  ordered_set window;
  int n,k;
  cin>>n>>k;
  vector<int>v(n);
  vector<int>W(n);
  for(int i = 0;i<n;i++)
  {
    cin>>v[i];
    W[i] = v[i];
  }
  sort(W.begin(), W.end());
  map<int,int>m;
  int j = 0;
  for(int i = 0;i<n;i++)
  {
    if (m.count(W[i])==0)
    {
      m[W[i]] = j;
      j++;
    }
  }

  vector<long long int>prefix_sum_array(m.size(),0);
  vector<long long int>fenwick_tree(m.size()+1, 0);
  vector<long long int> count_array(m.size(),0);
  vector<long long int> count_fenwick_tree(m.size()+1, 0);

  prefix_sum_array[0] = 0;
  
  if (k==1)
  {
    for(int i = 0;i<n;i++)
    {
      cout<<0<<" ";
    }
    cout<<endl;
    return 0;
  }
 
  for(int i = 0;i<k-1;i++)
  {
    window.insert(make_pair(v[i], i));
  }
  for(int i = 0;i<k-1;i++)
  {
    prefix_sum_array[m[v[i]]] += v[i];
    count_array[m[v[i]]]+=1;
    update(prefix_sum_array, fenwick_tree, m[v[i]], v[i]);
    update(count_array, count_fenwick_tree, m[v[i]], 1);
  }
  for(int i = k-1;i<n;i++)
  {
    window.insert(make_pair(v[i], i));
    auto it = window.find_by_order((k-1)/2);
    int median = (*it).first;
    window.erase(window.find(make_pair(v[i-k+1], i-k+1)));
    int index = m[median];
    prefix_sum_array[m[v[i]]] += v[i];
    count_array[m[v[i]]]+=1;
    update(count_array, count_fenwick_tree, m[v[i]], 1);
    update(prefix_sum_array, fenwick_tree, m[v[i]], v[i]);
    long long int sum = getSum(fenwick_tree, m.size()-1);
    long long int sum1 = getSum(fenwick_tree, index-1);
    long long int left_sum = getSum(count_fenwick_tree, index-1);
    long long int right_sum = k-left_sum-count_array[index];
   
    cout<<sum+(left_sum - right_sum)*median - prefix_sum_array[index] - 2*sum1<<" ";
    prefix_sum_array[m[v[i-k+1]]]-=v[i-k+1];
    count_array[m[v[i-k+1]]]-=1;
    update(prefix_sum_array, fenwick_tree,m[v[i-k+1]], - v[i-k+1]);
    update(count_array, count_fenwick_tree, m[v[i-k+1]], -1);
  }
  cout<<endl;
  return 0;
  
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  // # distinctval in arr[a:b] = # distinct in arr[0:b] - arr[0:a]
  int n,k;
  cin>>n>>k;
  vector<int>v(n);
  for(int i = 0;i<n;i++)
  {
    cin>>v[i];
  }
  map<int, int>m;
  // vector<int>distinct(n+1);
  // distinct[0] = 0;
  // int prev_j = 0;
  // int prev_i = 0;
  int j = 0;
  // int count = 0;
  vector<pair<int, int>> pairs_ij;
  for(int i = 0;i<n;i++)
  {
    m[v[i]] += 1;
    // distinct[i+1] = m.size();
    if(m.size() > k)
    {
      pairs_ij.push_back(make_pair(j,i-1));
      while(m.size()>k)
      {
        m[v[j]]--;
        if (m[v[j]]==0)
        {
          m.erase(v[j]);
        }
        j++;
      }
    }
  }
  pairs_ij.push_back(make_pair(j, n-1));
  long long int count = 0;
  for(int i = 0;i<pairs_ij.size();i++)
  {
    // cout<<pairs_ij[i].first<<" "<<pairs_ij[i].second<<endl;
    if (i==0)
    {
      int length = pairs_ij[i].second - pairs_ij[i].first+1;
      count+=(long long)(length*(length+1))/2;
    }
    else
    {
      int length = pairs_ij[i].second - pairs_ij[i].first+1;
      count+=(long long)(length*(length+1))/2;
      int common_length = pairs_ij[i].first - pairs_ij[i-1].second+1;
      count -= (long long)(common_length*(common_length+1))/2;

    }
  }
  // if (m.size()<=k)
  // {
  //   cout<<(long long)(n*(n+1))/2<<endl;
  //   return 0;
  // }
  // int x = n-j;
  // count += (long long)(x*(x+1))/2;
  cout<<count<<endl;
  return 0;
  
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,k;
  cin>>n>>k;
  vector<int>v(n);
  for(int i = 0;i<n;i++)
  {
    cin>>v[i];
  }
  map<int, int>m;

  int j = 0;
  vector<pair<int, int>> pairs_ij;
  for(int i = 0;i<n;i++)
  {
    m[v[i]] += 1;
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
    if (i==0)
    {
      long long int length = pairs_ij[i].second - pairs_ij[i].first+1;
      count+=(length*(length+1))/2;
    }
    else
    {
      long long int length = pairs_ij[i].second - pairs_ij[i].first+1;
      count+=(length*(length+1))/2;
      long long int common_length = pairs_ij[i-1].second - pairs_ij[i].first+1;
      count -= (common_length*(common_length+1))/2;

    }
  }

  cout<<count<<endl;
  return 0;
  
}
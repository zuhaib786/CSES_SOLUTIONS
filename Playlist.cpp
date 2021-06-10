#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int> v(n);
  map<int, vector<int>> m;
  for(int i = 0;i<n;i++)
  {
    cin>>v[i];
    if (m.find(v[i])!=m.end())
    {
      m[v[i]].push_back(i);
    }
    else
    {
      m[v[i]] = vector<int>();
      m[v[i]].push_back(i);
    }
  }
  map<int,int>index;
  for (auto i: m)
  {
    index[i.first] = -1;
  }
  int max_size = 0;
  int prev_index = -1;
  int size = 0;
  for (int i = 0; i<n;i++)
  {
    int val = index[v[i]];
    if (val == -1)
    {
      size++;
      index[v[i]]++;
    }
    else
    {
      if (prev_index == -1)
      {
        size = (i - m[v[i]][index[v[i]]]);
        prev_index = m[v[i]][index[v[i]]];
      }
      else
      {
        prev_index = max(prev_index, m[v[i]][index[v[i]]]);
        size = (i - prev_index);
      }
      index[v[i]]++;
    }
    // cout<<size<<" "<<prev_index<<endl;
    max_size = max(size, max_size);
  }
  cout<<max_size<<endl;
  return 0;
}
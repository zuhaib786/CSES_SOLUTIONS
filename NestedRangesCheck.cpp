#include <bits/stdc++.h>
using namespace std;

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
  int max_range = 0, min_range = 1e9+7, i = 0, j = n-1;
  for(; i<n && j>=0; i++, j--)
  {
    range r1 = v[i];
    if (r1.second <= max_range)
    {
      is_contained[v[i].index] = 1;
    }
    max_range = max(max_range, r1.second);
    range r2 = v[j];
    if (r2.second >= min_range)
    {
      contains[v[j].index] = 1;
    }
    min_range = min(min_range, r2.second);
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
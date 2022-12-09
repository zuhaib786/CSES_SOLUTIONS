#include <bits/stdc++.h>
using namespace std;

pair<int, int> getSum(vector<pair<int, int> > &v, int left_index, int x)
{
  int right_index = v.size()-1;
  while (left_index<right_index)
  {
    if (v[left_index].first+v[right_index].first>x)
    {
      right_index--;
    }
    else if (v[left_index].first+v[right_index].first<x)
    {
      left_index++;
    }
    else
    {
      return make_pair(left_index, right_index);
    }
  }
  return make_pair(-1,-1);
}

int main() {
  int n,x;
  cin>>n>>x;
  vector<pair<int, int>>v(n);
  for(int i =0;i<n;i++)
  {
    cin>>v[i].first;
    v[i].second = i;
  }
  if(n<4)
  {
    cout<<"IMPOSSIBLE\n";
    return 0;
  }
  sort(v.begin(), v.end());
  for(int i = 0;i<n-2;i++)
  {
    for(int j = i+1;j<n-1;j++)
    {
      pair<int, int> p = getSum(v, j+1, x-v[i].first-v[j].first);
      if (p.first!=-1)
      {
        vector<int> ans(4);
        ans[0] = v[i].second+1;
        ans[1] = v[p.first].second+1;
        ans[2] = v[p.second].second+1;
        ans[3] = v[j].second+1;
        sort(ans.begin(), ans.end());
        cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<" "<<ans[3]<<"\n";
        return 0;
      }
    }
  }
  cout<<"IMPOSSIBLE\n";
  return 0;
  
}
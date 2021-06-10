#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  multiset <int, greater <int> > Towers;
  int count = 0;
  for(int i = 0;i<n;i++)
  {
    int k;
    cin>>k;
    auto it = Towers.lower_bound(-(k+1));
    if (it == Towers.end())
    {
      count++;
      // cout<<"K: "<<k<<endl;
      Towers.insert(-k);
    }
    else
    {
      // cout<<"*it "<<-(*it)<<endl;
      Towers.erase(it);
      Towers.insert(-(k+1));
    }
  }
  cout<<count<<endl;
}
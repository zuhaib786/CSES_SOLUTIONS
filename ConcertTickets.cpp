#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,m;
  cin>>n>>m;
  multiset <int, greater <int> > ticket_prices;
  vector<int >max_prices(m);
  for(int i = 0;i<n;i++)
  {
    int k;
    cin>>k;
    ticket_prices.insert(k);
  }
  for(int i = 0;i<m;i++)
  {
    cin>>max_prices[i];
  }
  int i = 0;
  int j = 0;
  vector<int>ans;
  for(int i = 0;i<m;i++)
  {
    // cout<<max_prices[i]<<endl;
    if (ticket_prices.find(max_prices[i])!=ticket_prices.end())
    {
      auto it = ticket_prices.find(max_prices[i]);
      // cout<<*it<<" "<<max_prices[i]<<endl;
      ans.push_back(max_prices[i]);
      ticket_prices.erase(it);
      continue;
    }
    auto it = ticket_prices.upper_bound(max_prices[i]);
    if (it!=ticket_prices.end())
    {
      // cout<<*it<<" "<<max_prices[i]<<endl;
      ans.push_back((*it));
      ticket_prices.erase(it);
    }
    else
    {
      ans.push_back(-1);
    }
  }
  for(int i = 0;i<ans.size();i++)
  {
    cout<<ans[i]<<"\n";
  }
  return 0;
}
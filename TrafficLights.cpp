#include <bits/stdc++.h>
using namespace std;

int main() {
  int x,n;
  cin>>x>>n;
  multiset<int>gaps;
  set<int> lights;
  lights.insert(x);
  lights.insert(0);
  gaps.insert(x);
  for(int i = 0; i<n ; i++)
  {
    int k;
    cin>>k;
    auto it = lights.upper_bound(k);
    auto prev = it;
    prev--;
    int gap = (*it)- (*prev);
    gaps.erase(gaps.find(gap));
    gaps.insert(k-(*prev));
    gaps.insert( (*it)  - k);
    lights.insert(k);
    auto max_it = gaps.end();
    
    max_it--;
    cout<< *max_it<<endl;
  }
  return 0;
}
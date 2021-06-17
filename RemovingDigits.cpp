#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000007
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(NULL); 
  int n;
  cin>>n;
  vector<int>v(n+1, MAX);
  v[0] = 0;
  for(int i = 1;i<=n;i++)
  {
      string s =to_string(i);
      for(auto c: s)
      {
          v[i] = min(v[i], v[i- (int)c + (int)'0']+1) ;
      }
  }
  cout<<v[n]<<endl;
}
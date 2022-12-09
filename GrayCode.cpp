#include <bits/stdc++.h>
using namespace std;
void next(vector<string>&v)
{
  vector<string>ref(v.size());
  for(int i = 0;i<v.size();i++)
  {
    ref[i] = v[v.size()-1-i];
  }
  for(int i = 0;i<v.size();i++)
  {
    v[i] = "0"+v[i];
  }
  for(int i = 0;i<ref.size();i++)
  {
    v.push_back("1"+ref[i]);
  }

}
void printvec(vector<string>&v)
{
  for(int i = 0;i<v.size();i++)
  {
    cout<<v[i]<<"\n";
  }
}
int main() {
  vector<string>v(2);
  v[0] = "0";
  v[1] = "1";
  int n;
  cin>>n;
  if(n==1)
  {
    printvec(v);
  }
  else
  {
    for(int i = 1;i<n;i++)
    {
      next(v);
    }
    printvec(v);
  }

}
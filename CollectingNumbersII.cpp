#include <bits/stdc++.h>
using namespace std;
void LeftChange(vector<pair<int, int>> &v, vector<int> &orig, int &count, int a, int b)
{
  int val = orig[a];
  if (val == 1)
  {
    return;
  }
  int pos = v[val - 2].second;
  // cout<<"Val-2  "<<val-2<<" V.size() "<<v.size()<<" a "<<a<<" orig[a] "<<orig[a]<<endl;
  if (pos<a && pos>b)
  {
    count++;
  }
  else if (pos>a and pos<b)
  {
    count--;
  }
}
void RightChange(vector<pair<int, int>> &v, vector<int> &orig, int &count, int a, int b)
{
  int val = orig[a];
  if (val == v.size())
  {
    return;
  }
  int pos = v[val].second;
  // cout<<"Val  "<<val<<" V.size() "<<v.size()<<" a "<<a<<" orig[a] "<<orig[a]<<endl;
  if (pos<a && pos>b)
  {
    count--;
  }
  else if (pos>a and pos<b)
  {
    count++;
  }
}
void Change( vector<pair<int, int>> &v, vector<int> &orig, int &count, int a, int b )
{
  int val1 = orig[a];
  int val2 = orig[b];
  if (val1 == val2+1)
  {
    // cout<<"YES1\n";
    if (a<b)
    {
      count--;     
    }
    else
    {
      count++;
    }
    RightChange(v,orig, count, a, b);
    LeftChange(v,orig, count, b, a);

  }
  else if (val2 == val1+1)
  {
    // cout<<"YES2\n";
    if (a<b)
    {
      count++;     
    }
    else
    {
      count--;
    }
    RightChange(v,orig, count, b, a);
    LeftChange(v,orig, count, a, b);
  }
  else
  {
    RightChange(v,orig, count, a, b);
    LeftChange(v,orig, count, b, a);
    RightChange(v,orig, count, b, a);
    LeftChange(v,orig, count, a, b);
  }
}
int main() {
  // Number of points a[i]>a[i+1];
  int n,m;
  cin>>n>>m;
  vector<pair<int, int> >v(n);
  vector<int>orig(n);
  for(int i = 0;i<n;i++)
  {
    int k;
    cin>>k;
    v[i] = make_pair(k,i);
    orig[i] = k;
  }
  sort(v.begin(), v.end());
  if (v.size() == 1)
  {
    for (int j = 0;j<m;j++)
    {
      cout<<1<<endl;
    }
    return 0;
  }
  int count = 0;
  for(int i = 0;i<v.size()-1;i++)
  {
    if (v[i].second>v[i+1].second)
    {
      count++;
    }
  }
  // cout<<"Orig Priniting ----------------\n";
  // for(int i = 0;i<n;i++)
  // {
  //   cout<<orig[i]<<" ";
  // }
  // cout<<endl;
  for( int i = 0;i<m;i++)
  {
    int a,b;
    cin>>a>>b;
    Change(v, orig, count, a-1, b-1);
    int temp = orig[a-1];
    orig[a-1] = orig[b-1];
    orig[b-1] = temp;
    v[orig[a-1] - 1].second = a-1;
    v[orig[b-1] - 1].second = b-1;
    cout<<count+1<<endl;
  }
  
  return 0;
}
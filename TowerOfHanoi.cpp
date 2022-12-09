#include <bits/stdc++.h>
using namespace std;
void tower(int left, int mid, int right, int n, string &s, int &count)
{
  if (n==1)
  {
    count++;
    s+=to_string(left)+" "+to_string(right)+"\n";
    return;
  }
  tower(left, right, mid, n-1, s, count);
  count++;
  s+=to_string(left)+" "+to_string(right)+"\n";
  tower(mid, left, right, n-1, s, count);
}
int main() {
  int n;
  cin>>n;
  string s= "";
  int count = 0;
  tower(1,2,3,n,s,count);
  cout<<count<<"\n"<<s;
}
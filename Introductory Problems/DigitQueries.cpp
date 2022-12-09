#include <bits/stdc++.h>
using namespace std;
int nearest(long long int k)
{
  long long int pow = 10;
  int n = 1;
  while (true){
    long long int temp = n*pow - (pow-1)/9;
    if (temp > k)
    {
      return n-1;
    }
    pow*=10;
    n++;
  }
}
void integer(long long int k)
{
  if (k<10)
  {
    cout<<k<<endl;
    return;
  }
  int n = nearest(k);
  // cout<<"N: "<<n<<endl;
  long long int pow = 1;
  for(int i = 0;i<n;i++)
  {
    pow*=10;
  }
  k-= pow*n - (pow-1)/9;
  k-=1;
  if (k==-1)
  {
    cout<<9<<endl;
    return;
  }
  // cout<<k<<endl;
  long long int index = k/(n+1);
  index += pow;
  string s = to_string(index);
  cout<<s[k%(n+1)]<<endl; 
  return ;
}
int main() {
  int q;
  cin>>q;
  // q = 1;
  while(q--)
  {
    long long int k;
    cin>>k;
    // k = 189;
    integer(k);
  }
  return 0;
}
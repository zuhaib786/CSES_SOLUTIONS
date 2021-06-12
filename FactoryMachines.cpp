#include <bits/stdc++.h>
using namespace std;

long long int num_product(long long int time, vector<int> &rates, int limit)
{
  long long int ans = 0;
  for(int i =0 ; i< rates.size();i++)
  {
    if (ans>limit)
      return ans;
    ans+= time/rates[i];
  }
  return ans;
}
int max(vector<int> &v)
{
  int maxy = v[0];
  for(int i = 0;i<v.size();i++)
  {
    maxy = max(v[i], maxy); 
  }
  return maxy;
}
int main() {
  int n;
  long long int t;
  cin>>n>>t;
  vector<int>rates(n);
  for(int i = 0;i<n;i++)
  {
    cin>>rates[i];
  }
  long long int max_time = max(rates)*t +1;
  long long int min_time = 0;
  while (min_time < max_time)
  {
    long long int mid_time = min_time + (max_time-min_time)/2;
    if (num_product(mid_time, rates,t)>=t)
    {
      max_time = mid_time-1;
    }
    
    else if (num_product(mid_time, rates,t)<t)
    {
      min_time = mid_time+1;
    }
    else
    {
      break;
    }
  }
  if (num_product(min_time, rates,t)>=t)
  {
    while(num_product(min_time, rates,t)>=t)
    {
      min_time-=1;
    }
    cout<<min_time+1<<endl;
  } 
  else
  {
    while(num_product(min_time, rates,t)<t)
    {
      min_time+=1;
    }
    cout<<min_time<<endl;
  } 
  return 0;
}
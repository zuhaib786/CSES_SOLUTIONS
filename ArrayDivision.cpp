#include <bits/stdc++.h>
using namespace std;
int max_arr(vector<int> &v)
{
  int maxima = v[0];
  for(auto i: v)
  {
    maxima = max(maxima, i);
  }
  return maxima;
}

int get_count(vector<int>&v, long long int max_sum,int k)
{
  long long int cur_sum =0;
  int count= 0;
  for(int i = 0;i<v.size();i++)
  {
    if (v[i]> max_sum)
    {
      return k+1;
    }
    if(cur_sum + v[i]> max_sum)
    {
      cur_sum = 0;
      count++;
    }
    cur_sum += v[i];
  } 
  if (cur_sum!=0)
  {
    count++;
  }
  return count;
}
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  long long int maxima = 0;
  int n,k;
  cin>>n>>k;
  vector<int> v(n);
  for(int i = 0;i<n;i++)
  {
    cin>>v[i];
    maxima+= v[i];
  }
  long long int minima =0;
  while (minima+1<maxima)
  {
    long long int mid = minima + (maxima - minima)/2;
    int count = get_count(v, mid,k);
    if (count<=k)
    {
      maxima = mid ;
    }
    else
    {
      minima = mid;
    }
  }
  // if(get_count(v,minima,k)<k)
  // {
  //   cout<<minima<<endl;
  //   return 0;
  // }
  // while(get_count(v,minima)!=k)
  // {
  //   minima+=1;
  // }
  cout<<maxima<<endl;
  return 0;
  
}
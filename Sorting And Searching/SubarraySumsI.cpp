#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,x;
  cin>>n>>x;
  vector<int>v(n);
  for(int i = 0;i<n;i++)
  {
    cin>>v[i];
  }
  vector<long long int>sum_array(n+1);// sum_array[i] = sum(v[0:i])
  sum_array[0] = 0;
  for(int i = 0;i<n;i++)
  {
    sum_array[i+1] = sum_array[i] + v[i];
  }
  // sum[a:b] = x if and only sum_array[b] - sum_array[a] = x;
  int i = 0, j = 1;
  long long int count = 0;
  while (j < n+1)
  {
    if (sum_array[j]-sum_array[i] == x)
    {
      long long int init = sum_array[i];
      int val1= 0 , val2 = 0;
      while(sum_array[i] == init)
      {
        i++;
        val1++;
      }
      init = sum_array[j];
      while(j<n+1 && sum_array[j] == init)
      {
        j++;
        val2++;
      }
      count += (long long )val1*val2;
    }
    else if (sum_array[j]-sum_array[i] >x)
    {
      i++;
    }
    else
    {
      j++;
    }
  }
  cout<<count<<endl;
  return 0;
  
}
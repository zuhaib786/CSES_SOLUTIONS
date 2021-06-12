#include <bits/stdc++.h>
using namespace std;


int main() {
  int n;
  cin>>n;
  vector<int>v(n);
  for(int i = 0;i<n;i++)
  {
    cin>>v[i];
  }
  sort(v.begin(), v.end());
  int fast_reader = 0;
  int slow_reader = n-1;
  long long int fast_reader_time = 0;
  long long int slow_reader_time = 0;
  if(n==1)
  {
    cout<<2*v[0]<<endl;
    return 0;
  }
  while (fast_reader<=slow_reader)
  {
    if (fast_reader_time<slow_reader_time)
    {
      fast_reader_time += v[fast_reader];
      fast_reader++;
    }
    else
    {
      slow_reader_time += v[slow_reader];
      slow_reader--;
    }
  }
  if (slow_reader_time <= fast_reader_time)
  {
    cout<< slow_reader_time+fast_reader_time<<endl;
    return 0;
  }
  else
  {
    if (slow_reader+1!=n-1)
    {
      cout<< slow_reader_time+fast_reader_time<<endl;
      return 0;
    }
    else 
    {
      cout<< (slow_reader_time-fast_reader_time)+fast_reader_time+slow_reader_time<<endl; 
      return 0;
    }
  }
  return 0;
}
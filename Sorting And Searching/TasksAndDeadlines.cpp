#include <bits/stdc++.h>
using namespace std;


int main() {
  int n;
  cin>>n;
  vector<int> duration(n);
  vector<int> deadline(n);
  for(int i = 0;i<n;i++)
  {
    cin>>duration[i];
    cin>>deadline[i];
  }
  sort(duration.begin(), duration.end());
  long long int reward = 0;
  for(int i = 0;i<n;i++)
  {
    reward += deadline[i]-((long long)(n-i)*duration[i]);
  }
  cout<<reward<<endl;
  return 0;
}
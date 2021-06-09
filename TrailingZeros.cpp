#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    long long int count = 0;
    while(n!=0)
    {
        count+=n/5;
        n/=5;
    }
    cout<<count<<endl;
}
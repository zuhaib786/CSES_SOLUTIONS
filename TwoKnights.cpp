#include<bits/stdc++.h>
using namespace std;
void Two_Knights(long long n)
{
    long long arr[n];
    memset(arr,0,sizeof(arr));
    arr[1] = 6;
    arr[2] = 28;
    for(long long i = 3;i<n;i++)
    {
        long long k = i+1;
        arr[i] = ((k*k)*(k*k-1))/2-4*(k-1)*(k-2);
    }
    for(long long i = 0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}
int main()
{
    long long  n;
    cin>>n;
    Two_Knights(n);
    return 0;
}
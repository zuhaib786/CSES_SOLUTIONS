#include<iostream>
using namespace std;
const long long MOD = 1e9+7;
long long POW(long long x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    if(n%2==0)
    {
        long long z = POW(x,n/2);
        return (z*z)%MOD;
    }
    long long z = POW(x,n/2);
    return ((z*z)*x)%MOD;
}
int main()
{
    int n;
    cin>>n;
    cout<<POW(2,n)<<endl;
}
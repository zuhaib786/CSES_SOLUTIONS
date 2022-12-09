#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
int Pow(int a, int b, int MOD)
{
    if(b==0)
    {
        return 1;
    }
    if(b==1)
    {
        return a%MOD;
    }
    long long int x= Pow(a,b/2, MOD);
    if(b%2)
    {
        return ((x*x)%MOD*a)%MOD;
    }
    else
    {
        return (x*x)%MOD;
    }
}
int Pow1(int a, int b, int c)
{
    // b^c MOD , mO
    b = Pow(b,c, M-1);
    return Pow(a,b,M);
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a, b, c;
        cin>>a>>b>>c;
        cout<<Pow1(a,b,c)<<endl;
    }
}
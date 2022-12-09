#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int Pow(int a, int b)
{
    if(b==0)
    {
        return 1;
    }
    if(b==1)
    {
        return a%MOD;
    }
    long long int x= Pow(a,b/2);
    if(b%2)
    {
        return ((x*x)%MOD*a)%MOD;
    }
    else
    {
        return (x*x)%MOD;
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    while(n--)
    {
        int a, b;
        cin>>a>>b;
        cout<<Pow(a,b)<<endl;
    }
}
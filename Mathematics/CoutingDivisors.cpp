#include <bits/stdc++.h>
using namespace std;
#define M 1000000007

int count(int n)
{
    int x = ceil(sqrt(n));
    int cnt = 0;
    for(int i = 1; i*i<=n; i++)
    {
        if(n%i == 0)
        {
            cnt+=2;
        }
        if(i*i ==n)
        {
            cnt--;
        }
    }
    
    return cnt;
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        cout<<count(x)<<endl;
    }
    return 0;
}
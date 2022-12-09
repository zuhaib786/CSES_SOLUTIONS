#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
int range[1000000+1]; 
int main()
{
    int n;
    cin>>n;
    memset(range, 0, sizeof(range));
    while(n--)
    {
        int k;
        cin>>k;
        range[k]+=1;
    }
    for(int gcd = 1000000; gcd>=1; gcd--)
    {
        int count = 0;
        for(int ptr = gcd; ptr<1000001; ptr+=gcd)
        {
            count+=range[ptr];
        }
        if(count>=2)
        {
            cout<<gcd<<endl;
            break;
        }
    }
}
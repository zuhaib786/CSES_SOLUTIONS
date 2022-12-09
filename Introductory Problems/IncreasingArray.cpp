#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long int cost = 0;
    int curr;
    cin>>curr;
    for(int i = 0;i<n-1;i++)
    {
        int k;
        cin>>k;
        if (k<curr)
        {
            cost += curr-k;
        }
        else
        {
            curr = k;
        }
    }
    cout<<cost<<endl;
    return 0;
}
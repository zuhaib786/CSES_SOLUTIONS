#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        long long int x,y;
        cin>>x>>y;
        if (x==1)
        {
            if (y%2==1)
            cout<<y*y<<endl;
            else
            cout<<y*y-2*y+2<<endl;
        }
        else if (y==1)
        {
            if (x%2==0)
            cout<<x*x<<endl;
            else
            cout<<x*x-2*x+2<<endl;
        }
        else if (y==x)
        {
            cout<<x*x+1-x<<endl;
        }
        else if (x>y)
        {
            if (x%2==0)
            cout<<x*x+1-y<<endl;
            else
            cout<<x*x-(x-1+(x-y))<<endl;
        }
        else
        {
            if (y%2 == 0)
           cout<<y*y-(y-1+(y-x))<<endl;
            else
            cout<<y*y+1-x<<endl;
        }
 
    }
    return 0;
}
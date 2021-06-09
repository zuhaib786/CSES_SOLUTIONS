#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int a,b;
        cin>>a>>b;
        if((a == 0 &&b!=0)||(b==0 && a!=0 ))
        {
            cout<<"NO\n";
        }
        else
        if ((2*a-b)%3==0 && (2*b-a)%3==0 && (2*a-b)>=0 && (2*b-a)>=0)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
 
    }
    return 0;
}
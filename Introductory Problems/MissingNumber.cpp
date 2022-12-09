#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    memset(arr,0,sizeof(arr));
    for(int i = 0;i<n-1;i++)
    {
        int x;
        cin>>x;
        arr[x-1] = 1;
    }
    for (int i = 0;i<n;i++)
    {
        if (arr[i]==0)
        {
            cout<<i+1<<endl;
            return 0;
        }
    }
    return 0;
}
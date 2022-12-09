#include<bits/stdc++.h>
using namespace std;
int main()
{
    // Coding in c++;
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr, arr+n);
    int count = 1;
    int prev = arr[0];
    for (int i = 0;i<n;i++)
    {
        if (arr[i] == prev)
        {
            continue;
        }
        else
        {
            count++;
            prev = arr[i];
        }
        
    }
    cout<<count<<"\n";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    if(n%4 == 1 ||n%4 == 2)
    {
        cout<<"NO\n";
        return 0;
    }
    int arr[n+1];
    memset(arr,0,sizeof(arr));
    long long sum = 0;
    long long cost = (n*(n+1))/4;
    long long cur = n;
    while(cost-sum>cur)
    {
        sum+=cur;
        arr[cur] = 1;
        cur = cur-1;
    }
    arr[cost-sum] = 1;
    cout<<"YES\n";
    string s1 = "";
    string s2 = "";
    int count1 = 0;
    int count2 = 0;
    for(long long i = 1; i<=n;i++)
    {
        if(arr[i] == 0)
        {
            if (s1.size()==0)
            {
                s1+=to_string(i);
                count1++;
            }
            else{
                s1+=" "+to_string(i);
                count1++;
            }
        }
        else
        {
            if(s2.size()==0)
            {
                s2+=to_string(i);
                count2++;
            }
            else
            {
                s2+=" "+to_string(i);
                count2++;
            }
        }
    }
    cout<<count1<<"\n"<<s1+"\n"+to_string(count2)+"\n"+s2+"\n";
    return 0;
}
    #include<bits/stdc++.h>
    #define MAX 1000000007
    using namespace std; 
   
    int main()
    {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        cout.tie(NULL);
        int n,q;
        cin>>n>>q;
        vector<long long int>prefix_sum(n+1,0);
        for(int i = 0 ; i<n;i++)
        {
            cin>>prefix_sum[i+1];
            prefix_sum[i+1]+=prefix_sum[i];
        }
        for(int i = 0 ; i<q;i++)
        {
            int a, b;
            cin>>a>>b;
            a--;
            b--;
            cout<<prefix_sum[b+1]-prefix_sum[a]<<endl;
        }
        return 0;
    }
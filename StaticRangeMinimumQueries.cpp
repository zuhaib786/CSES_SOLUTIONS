    #include<bits/stdc++.h>
    #define MAX 1000000007
    using namespace std; 
    int getPow(int n)
    {
        int k =1;
        int count = 1;
        while(k<=n)
        {
            k*=2;
            count++;
        }
        return count-1;
    }
    int main()
    {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        cout.tie(NULL);
        int n,q;
        cin>>n>>q;
        vector<long long int>v(n,0);
        for(int i = 0 ; i<n;i++)
        {
            cin>>v[i];
            
        }
        int k = getPow(n);
        vector<vector<int>>ans(k, vector<int> (1<<k,0));
        for(int i = n;i<1<<k;i++)
        {
            v.push_back(MAX);
        }
        for(int i = 0 ; i<1<<k;i++)
        {
            ans[0][i] =v[i];
        }
        for(int i =1; i<k;i++)
        {
            for(int j = 0;j+(1<<(i-1))<1<<k;j++)
            {
                ans[i][j] = min(ans[i-1][j], ans[i-1][j+(1<<(i-1))]);
            }
        }
        // for(auto vec: ans)
        // {
        //     cout<<"[";
        //     for(int x: vec)
        //     {
        //         cout<<x<<",";
        //     }
        //     cout<<"]"<<endl;
        // }
        for(int i = 0 ; i<q;i++)
        {
            int a, b;
            cin>>a>>b;
            a--;
            b--;
            int length = b-a+1;
            int p = -1;
            for(int i = 0; i<k;i++)
            {
                if(length&1<<i)
                {
                    if(p == -1)
                    {
                        p = ans[i][a];
                        a = a+(1<<i); 
                    }
                    else
                    {
                        p = min(ans[i][a],p);
                        a = a+(1<<i);
                    }
                }
            }
            cout<<p<<endl;
        }
        return 0;
    }
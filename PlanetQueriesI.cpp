    #include<bits/stdc++.h>
    #define MAX 1000000007
    using namespace std; 
   
    
    int main()
    {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        // precomputation is the key.
        int n,q;
        cin>>n>>q;
        vector<int>telep(n);
        for(int i = 0; i<n;i++)
        {
            cin>>telep[i];
            telep[i]--;
        }
        vector<vector<int>>pos(n, vector<int>(30, -1));
        for(int i = 0; i<n;i++)
        {
            pos[i][0] = telep[i];
        }
       
        for(int j =1; j<30;j++)
        {
            for(int i = 0 ; i<n;i++)
            {
                int telep_pos = pos[i][j-1];
                pos[i][j] = pos[telep_pos][j-1];
            }
        }
        for(int i = 0 ; i<q;i++)
        {
            int x,k;
            cin>>x>>k;
            x--;
            for(int j = 30; j>=0;j--)
            {
                if(k&1<<j)
                {
                    x = pos[x][j];
                }
            }
            cout<<x+1<<endl;
        }
        return 0;
        

    }
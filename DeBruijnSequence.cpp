    #include<bits/stdc++.h>
    #define MAX 1000000007
    using namespace std; 
    vector<string>alphabet = {"0", "1"};
    int k = 2;
    vector<int>sequence;
    vector<int>a;
    int n;
    void db(int t, int p)
    {
        if(t>n)
        {
            if(n%p==0)
            {
                for(int i = 1;i<=p;i++)
                {
                    sequence.push_back(a[i]);
                }
            }
        }
        else
        {
            a[t] = a[t-p];
            db(t+1, p);
            for(int j = a[t-p]+1;j<k;j++)
            {
                a[t] = j;
                db(t+1, t);
            }
        }
    }
    int main()
    {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        cout.tie(NULL);
        /*
        source: https://en.wikipedia.org/wiki/De_Bruijn_sequence
        */
       cin>>n;
       a = vector<int>(n*k, 0);
       db(1,1);
       for(auto x: sequence)
       {
           cout<<x;
       }
       for(int i = 0 ; i<n-1;i++)
       {
           cout<<sequence[i];
       }
       cout<<endl;
        return 0;
    }
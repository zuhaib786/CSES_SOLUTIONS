    #include <bits/stdc++.h>
    using namespace std;

    int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    int n;
    cin>>n;
    vector<int>v(n+1, 0);
    v[0] = 1;
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=6;j++)
        {
            if (i>=j)
            {
                v[i] += v[i-j];
                v[i]=v[i]%(1000000007);
            }
        }
    }
    cout<<v[n]<<endl;
    }
#include<bits/stdc++.h>
#define MAX 1000000007
using namespace std; 
const int maxN = 2e5 + 5;
int pos[maxN][30];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    // precomputation is the key.
    int n,q;
    cin>>n>>q;
    int telep[n];
    memset(pos, -1, sizeof(pos));
    for(int i = 0; i<n;i++)
    {
        cin>>telep[i];
        telep[i]--;
    }
   
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
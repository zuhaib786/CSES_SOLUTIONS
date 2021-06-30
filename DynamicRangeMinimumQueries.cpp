#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000007
// Segment Tree.
int seg_tree[16*(100005)];
void build(int a[], int v, int l , int r)
{
    if(l==r)
    {
        seg_tree[v] = a[l];
    }
    else
    {
        int m =(l+r)/2;
        build(a, v*2, l,m);
        build(a, v*2+1, m+1, r);
        seg_tree[v] = min(seg_tree[2*v], seg_tree[2*v+1]);
    }
}
int getMin(int v, int tl, int tr, int l, int r)
{
    if(l>r)
    {
        return MAX;
    }
    if(l==tl && r==tr)
    {
        return seg_tree[v];
    }
    int m = (tl+tr)/2;
    return min(getMin(2*v, tl, m, l, min(r, m)), getMin(2*v+1, m+1, tr, max(l,m+1), r));
}
void update(int v, int tl, int tr, int pos, int new_val)
{
    if(tl==tr)
    {
        seg_tree[v] = new_val;
    }
    else
    {
        int m = (tl+tr)/2;
        if(pos<=m)
        {
            update(v*2, tl, m, pos, new_val);
        }
        else
        {
            update(v*2+1,  m+1, tr, pos, new_val);
        }
        seg_tree[v] = min(seg_tree[2*v], seg_tree[2*v+1]);
    }
}
int main()
    {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        cout.tie(NULL);
        int n,q;
        cin>>n>>q;
        int a[n];
        for(int i = 0;i<n;i++)
        {
            cin>>a[i];
        }
        build(a,1, 0, n-1);
        // for(int i = 1; i<=4*n;i++)
        // {
        //     cout<<seg_tree[i]<<" ";
        // }
        // cout<<endl;
       
        for(int i = 0; i<q;i++)
        {
            int type, x, b;
            cin>>type>>x>>b;
            if(type == 1)
            {
                x--;
                update(1,0,n-1,x,b);
                // for(int i = 1; i<=4*n;i++)
                // {
                //     cout<<seg_tree[i]<<" ";
                // }
                // cout<<endl;
            }
            else
            {
                x--;
                b--;
                cout<<getMin(1,0,n-1,x,b)<<endl;
            }
        }
        return 0;
    }
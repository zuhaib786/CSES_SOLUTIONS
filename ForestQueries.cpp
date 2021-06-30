#include <bits/stdc++.h>
using namespace std;
int seg_tree[4005][4005];
int a[1000][1000];
int n;
void build_y(int vx, int lx, int rx, int vy, int ly, int ry)
{
    if(ly == ry)
    {
        if(lx==rx)
            seg_tree[vx][vy] = a[lx][ly];
        else
            seg_tree[vx][vy] = seg_tree[vx*2][vy] + seg_tree[vx*2+1][vy];    
    }
    else
    {
        int my = (ly+ry)/2;
        build_y(vx, lx, rx, vy*2, ly, my);
        build_y(vx, lx, rx, vy*2+1, my+1, ry);
        seg_tree[vx][vy] = seg_tree[vx][vy*2] + seg_tree[vx][vy*2+1];

    }
}
void build_x(int vx, int lx, int rx)
{
    if(lx!=rx)
    {
        int mx = (lx+rx)/2;
        build_x(vx*2, lx, mx);
        build_x(vx*2+1, mx+1, rx);
    }
    build_y(vx, lx, rx, 1, 0, n-1);
}
int sum_y(int vx, int vy, int tly , int t_r_y, int ly, int ry)
{
    if(ly>ry)
        return 0;
    if(ly==tly&&t_r_y == ry)
    {
        return seg_tree[vx][vy];
    }    
    int tmy = (t_r_y + tly)/2;
    return sum_y(vx, vy*2, tly,tmy, ly, min(ry, tmy) ) + sum_y(vx, vy*2+1, tmy+1, t_r_y, max(ly, tmy+1), ry);
}
int sum_x(int vx, int tlx,int trx, int lx, int rx, int ly, int ry)
{
    if(lx>rx)
        return 0;
    if(tlx == lx && trx == rx)
    {
        return sum_y(vx, 1, 0, n-1, ly, ry);
    }    
    int tmx = (tlx+ trx)/2;
    return sum_x(vx*2, tlx, tmx, lx, min(rx, tmx), ly, ry)+ sum_x(vx*2+1, tmx+1, trx, max(lx, tmx+1), rx, ly, ry);

}
int main()
    {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        cout.tie(NULL);
        int q;
        cin>>n>>q;
        for(int i = 0 ; i<n;i++)
        {
            string s;
            cin>>s;
            for(int j = 0; j<n;j++)
            {
                a[i][j] = s[j]=='*';
            }
        }
        
        build_x(1,0,n-1);
        
        
        for(int i = 0; i<q;i++)
        {
            int a, b,c,d;
            cin>>a>>b>>c>>d;
            a--;
            b--;
            c--;
            d--;
            cout<<sum_x(1,0,n-1,a,c,b,d)<<endl;
        }
        return 0;
    }
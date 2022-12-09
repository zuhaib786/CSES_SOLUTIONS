#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ways = 0;
bool cols[8],diag1[15],diag2[15],reserved[8][8];
void search(int row)
{
    if (row == 8)
    {
        ways++;
        return ;
    }
    for(int col = 0;col<8;col++)
    {
        if(cols[col]||diag1[row+col]||diag2[row-col+7]||reserved[row][col])
        {
            continue;
        }
        cols[col] = true;
        diag1[row+col] = true;
        diag2[row-col+7] = true;
        search(row+1);
        cols[col] = false;
        diag1[row+col] = false;
        diag2[row-col+7] = false;
    }
}
int main()
{
    memset(cols,false,sizeof(cols));
    memset(diag1,false,sizeof(diag1));
    memset(diag2,false,sizeof(diag2));
    for(int i = 0;i<8;i++)
    {
        string x;
        cin>>x;
        for(int j = 0;j<8;j++)
        {
            reserved[i][j] = x[j] != '.';
        }
    }
    search(0);
    cout<<ways<<endl;
}
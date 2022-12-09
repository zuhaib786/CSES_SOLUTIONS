#include<bits/stdc++.h>
using namespace std;
bool visited[7][7];
int steps;
// int max_steps;
int paths;
int reserved[48];
void search(int r, int c)
{
    // max_steps = max(steps,max_steps);
    // cout<<max_steps<<endl;
    if (r==6 && c == 0)
    {
        if (steps == 48)
        {
            paths+=1;
        }
        return;
    }
    if (visited[r][c])
    {
        return;
    }
    visited[r][c] = true;
    if(reserved[steps]== -1)
    {
        if(r>0 && !visited[r-1][c])
        {
            steps++;
            search(r-1,c);
            steps--;
        }
        if(r<6 && !visited[r+1][c])
        {
            steps++;
            search(r+1,c);
            steps--;
        }
        if(c>0 && !visited[r][c-1])
        {
            steps++;
            search(r,c-1);
            steps--;
        }
        if(c<6&&!visited[r][c+1])
        {
            steps++;
            search(r,c+1);
            steps--;
        }
    }
    else if (reserved[steps] == 1)
    {
        if (c<6 && !visited[r][c+1])
        {
            steps++;
            search(r,c+1);
            steps--;
        }
        // return;
    }
    else if (reserved[steps] == 2)
    {
        if (c>0 && !visited[r][c-1])
        {
            steps++;
            search(r,c-1);
            steps--;
        }
        // return;
    }
    else if (reserved[steps] == 3)
    {
        if (r>0 && !visited[r-1][c])
        {
            steps++;
            search(r-1,c);
            steps--;
        }
        // return;
    }
    else if (reserved[steps] == 4)
    {
        if (r<6 && !visited[r+1][c])
        {
            steps++;
            search(r+1,c);
            steps--;
        }
        // return;
    }
    visited[r][c] = false;
    return;
}
int main()
{
    // max_steps = 0;
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    paths = 0;
    steps = 0;
    memset(visited,false,sizeof(visited));
    string s;
    cin>>s;
    for(int i = 0;i<s.size();i++)
    {
        if(s[i]=='R')
        reserved[i] = 1;
        else if (s[i]=='L')
        reserved[i] =2;
        else if (s[i]=='U')
        reserved[i] = 3;
        else if (s[i]=='D')
        reserved[i] = 4;
        else
        reserved[i] = -1;
    }
    search(0,0);
    cout<<paths<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
inline int max(int a,int b)
{
    return a<b?b:a;
}
int main()
{
    string s;
    cin>>s;
    char cur = s[0];
    int len = 1;
    int maxlength = 1;
    for(int i = 1;i<s.size();i++)
    {
        if (s[i] == cur)
        {
            cur = s[i];
            len+=1;
            maxlength = max(maxlength,len);
        }
        else
        {
            len =1;
            cur = s[i];
        }
    }
    cout<<maxlength<<endl;
}
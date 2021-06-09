#include<bits/stdc++.h>
using namespace std;
void createAll(string s, vector<char>v, set<string>&perms)
{
    if (v.size()==0)
    {
        perms.insert(s);
        return ;
    }
    for(int i=0;i<v.size();i++)
    {
        string j = s;
        j+=v[i];
        vector<char>temp = v;
        temp.erase(temp.begin()+i);
        createAll(j,temp,perms);
    }
}
int main()
{
    string s;
    cin>>s;
    vector<char>v(s.size());
    for(int i = 0;i<s.size();i++)
    {
        v[i] = s[i];
    }
    string j = "";
    set<string>perms;
    createAll(j,v,perms);
    cout<<perms.size()<<endl;
    for(string x:perms)
    {
        cout<<x<<endl;
    }
    return 0;
 
}
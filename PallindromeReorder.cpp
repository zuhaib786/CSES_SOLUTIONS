#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int arr[26];
    memset(arr,0,sizeof(arr));
    int num_odd = 0;
    for(char x:s)
    {
        int z = (int)x-(int)'A';
        if(arr[z]%2==1)
        {
            num_odd-=1;
        }
        else
        {
            num_odd+=1;
        }
 
        arr[z]++;
    }
    if (num_odd>=2)
    {
        cout<<"NO SOLUTION\n";
        return 0;
    }
    int index = 0;
    for(int i = 0;i<26;i++)
    {
        if (arr[i]!=0)
        {
            if(arr[i]%2==0)
            {
                while(arr[i]!=0)
                {
                    s[index] = (char)(i+(int)'A');
                    s[s.size()-1-index] = (char)(i+(int)'A');
                    arr[i]-=2;
                    index++;
                }
            }
            else
            {
                s[(s.size())/2] =(char)(i+(int)'A');
                arr[i]-=1;
                while(arr[i]!=0)
                {
                    s[index] = (char)(i+(int)'A');
                    s[s.size()-1-index] = (char)(i+(int)'A');
                    arr[i]-=2;
                    index++;
                }
            }
 
        }
 
    }
    cout<<s<<endl;
    return 0;
}
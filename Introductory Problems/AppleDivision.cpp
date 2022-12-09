#include<iostream>
using namespace std;
void Count_Maxima(long long int &min_diff,long long int data[],int n,long int i ,long long int sum)
{
    long long count = 0;
    for(int j = 0;j<n;j++)
    {
        if (i&1<<j)
        {
            count+=data[j];
        }
    }
    if (min_diff>abs(sum-2*count))
    {
        min_diff = abs(sum - 2*count);
    }
}
int main()
{
    int n;
    cin>>n;
    long long data[n];
    long long int sum = 0;
    for(int i = 0;i<n;i++)
    {
        cin>>data[i];
        sum+=data[i];
    }
    long long int min_diff = sum;
    for(long long int i = 0;i<1<<n;i++)
    {
        Count_Maxima(min_diff,data,n,i,sum);
    }
    cout<<min_diff<<endl;
}
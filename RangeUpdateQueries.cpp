#include <bits/stdc++.h>
using namespace std;
void update(vector<long long int>&v, vector<long long int>&fenwick_tree, int index, int val)
{
  index++;
  while(index<=v.size())
  {
    fenwick_tree[index]+=val;
    index += index&(-index);// Get next
  }
}
long long  getSum(vector<long long int> &fenwick_tree, int index)
{
  index ++;
  long long int sum = 0;
  while (index>0)
  {
    sum+= fenwick_tree[index];
    index -= index &(-index);// Get parent;
  }
  return sum;
}

int main()
    {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        cout.tie(NULL);
        int n,q;
        cin>>n>>q;
        vector<long long int>fenwick_tree(n+2,0);
        vector<long long int>v(n+1,0);
        vector<int>vec(n,0);
        for(int i = 0 ; i<n;i++)
        {
            cin>>vec[i];
        }
        for(int i = 0 ; i<q;i++)
        {
            int x;
            cin>>x;

            if(x==1)
            {
                
                int a,b,u;
                cin>>a>>b>>u;
                a--,b--;
                v[a]+= u;
                v[b+1]+= -u;
                update(v,fenwick_tree,a,u);
                update(v,fenwick_tree,b+1, -u);
            }
            else
            {
                int k;
                cin>>k;
                k--;
                cout<<vec[k]+getSum(fenwick_tree,k)<<endl;    
            }
        }
        return 0;
    }
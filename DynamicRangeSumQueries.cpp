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
        vector<long long int>fenwick_tree(n+1,0);
        vector<long long int>v(n,0);
        for(int i = 0 ; i<n;i++)
        {
            cin>>v[i];
            update(v, fenwick_tree, i, v[i]);
        }
        for(int i = 0 ; i<q;i++)
        {
            int x,a,b;
            cin>>x>>a>>b;
            a--;

            if(x==1)
            {
                
                update(v,fenwick_tree,a, b-v[a] );
                v[a] = b;
            }
            else
            {
                b--;
                long long int sum = getSum(fenwick_tree, b);
                if(a==0)
                {
                    cout<<sum<<endl;
                }
                else
                {
                    sum -=getSum(fenwick_tree, a-1);
                    cout<<sum<<endl;
                }
            }
        }
        return 0;
    }
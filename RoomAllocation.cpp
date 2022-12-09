#include <bits/stdc++.h>
using namespace std;


int main() {
  int n;
  cin>>n;
  vector<pair<int, int>> v(2*n);
  for(int i = 0; i< n;i++)
  {
    cin>>v[2*i].first;
    cin>> v[2*i+1].first;
    v[2*i].second = i;
    v[2*i+1].second = n+i;
  }
  sort(v.begin(), v.end());
  int max_room =0;
  vector<int>ans(n);
  vector<int>free_rooms;
  map<int, int> room_assignment;
  int cur_cnt = 0;
  for(int i = 0; i<2*n;i++)
  {
    if (v[i].second<n)
    {
      cur_cnt+=1;
      if (free_rooms.size()==0)
      {
        ans[v[i].second] = cur_cnt;
        room_assignment[v[i].second] = cur_cnt;
      }
      else
      {
        ans[v[i].second] = free_rooms[free_rooms.size()-1];
        room_assignment[v[i].second] = free_rooms[free_rooms.size()-1];
        free_rooms.pop_back();
      }
    }
    else
    {
      int index = v[i].second-n;
      free_rooms.push_back(room_assignment[index]);
      room_assignment.erase(index);
      cur_cnt--;
    }
    max_room = max(max_room, cur_cnt);
  }
  cout<<max_room<<"\n";
  for(int i = 0; i<n;i++)
  {
    cout<<ans[i]<<" ";
  }
  cout<<"\n";

  return 0;
}
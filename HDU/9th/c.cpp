#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define x first
#define y second
typedef pair<int,int> pii;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int f(int x)
{
  int cnt=0;
  while(x>1)x/=2,cnt++;
  return cnt;
}
unordered_map<int,int>mp;
int bfs(int n){
  priority_queue<pii,vector<pii>,greater<pii>>q;
  q.push({n,0});
  mp.clear();
  mp[1]=1e9+10;
  // int cnt=0;
  while(!q.empty())
  {
    // cnt++;
    pii u=q.top();
    q.pop();
    if(mp.count(u.x)&&u.y>mp[u.x])continue;
    if(u.y+f(u.x)>mp[1])continue;
    mp[u.x]=u.y;
    int now=u.x;
    int t;
    if(now%3==0)
    {
      t=now/3;
      if(!mp.count(t)||mp[t]>u.y+1)mp[t]=u.y+1,q.push({t,u.y+1});
    }
    if(now%2==0)
    {
      t=now/2;
      if(!mp.count(t)||mp[t]>u.y+1)mp[t]=u.y+1,q.push({t,u.y+1});
    }
    t=u.x-1;
    if(!mp.count(t)||mp[t]>u.y+1)mp[t]=u.y+1,q.push({t,u.y+1});
  }
  // cout<<cnt<<" 666"<<endl;
  return mp[1];
}
void solve()
{
  // int n;cin>>n;
  // for(int i=1;i<=10000;i++){
  //   // cout<<i<<' '<<bfs(i)<<endl;
  // }
  for(int i=1;i<1000;i++){
    
      cout<<bfs(i)<<endl;
  }

  // cout<<mp.size()<<endl;
}
signed main(){
  int _=1;
  // cin>>_;
  while(_--)solve();
  // system("pause");
  return 0;
}
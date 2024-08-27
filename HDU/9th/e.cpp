#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define x first
#define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
unordered_map<int,int>mp;
// unordered_map<int,int>mp2;
void bfs(int n){
    queue<PII>q;
    q.push({n,0});
    mp.clear();
    while(q.size()){
        auto t=q.front();
        q.pop();
        // cout<<t.x<<' '<<t.y<<endl;
        if(mp[t.x]<t.y)continue;
        if(t.x==1){
            mp[1]=min(mp[1],t.y);
        }
        if(t.x/2>0&&(!mp.count(t.x/2)||mp[t.x/2]>t.y+1+t.x%2)){q.push({t.x/2,t.y+1+t.x%2});mp[t.x/2]=t.y+1+t.x%2;}
        if(t.x/3>0&&(!mp.count(t.x/3)||mp[t.x/3]>t.y+1+t.x%3)){q.push({t.x/3,t.y+1+t.x%3});mp[t.x/3]=t.y+1+t.x%3;}
    }
}
void solve()
{
    int n;cin>>n;
    bfs(n);b
    // cout<<<<endl;
    cout<<mp[1]<<endl;
    // cout<<mp.size()<<endl;
    // int t=1;
    // while(t<n){
    //     cout<<t<<endl;
    //     t=mp2[t];
    // }
    // cout<<n<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
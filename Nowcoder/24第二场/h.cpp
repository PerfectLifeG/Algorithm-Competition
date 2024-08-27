#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n,X,Y;cin>>n>>X>>Y;
    string s;cin>>s;
    map<PII,int>mp;
    if(X||Y)mp[{0,0}]=1;
    int ans=0;
    int x=0,y=0;
    for(int i=0;i<n;i++){
        if(s[i]=='A')x--;
        if(s[i]=='D')x++;        if(s[i]=='S')y--;
        if(s[i]=='W')y++;
        mp[{x,y}]++;
        if(mp.count({x-X,y-Y})){
            ans+=mp[{x-X,y-Y}]*(n-i);
            mp[{x-X,y-Y}]=0;
        }
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
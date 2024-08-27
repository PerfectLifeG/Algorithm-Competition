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

int dir[4][2]={1,0,0,-1,-1,0,0,1};
void solve(){
    int n;cin>>n;
    vector<PII>v[4];
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        string s;cin>>s;
        if(s=="E")v[0].push_back({a,b});
        if(s=="S")v[1].push_back({a,b});
        if(s=="W")v[2].push_back({a,b});
        if(s=="N")v[3].push_back({a,b});
    }

    auto check=[&](int mid){
        if(mid==-1)return INF;
        int a=-INF,b=INF,c=INF,d=-INF;
        for(int i=0;i<4;i++){
            for(auto &[x,y]:v[i]){
                int tx=x+dir[i][0]*mid,ty=y+dir[i][1]*mid;
                a=max(a,ty);
                b=min(b,ty);
                c=min(tx,c);
                d=max(tx,d);
            }
        }
        return (a-b)*2+(d-c)*2;
    };

    int l=-1,r=1e9;
    while(l+1!=r){
        int mid=l+r>>1;
        if(check(mid)<=check(mid-1))l=mid;
        else r=mid;
    }
    int ans=INF;
    for(int i=-100;i<100;i++){
        if(i>=0)ans=min(ans,check(l+i));
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
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
    int n,q;cin>>n>>q;
    map<PII,int>mp;
    vector<int>fa(n+1);
    for(int i=0;i<n-1;i++){
        int a,b,c;cin>>a>>b>>c;
        mp[{a,b}]=c;
        mp[{b,a}]=c;
        fa[b]=a;
    }    

    while(q--){
        int a,b;cin>>a>>b;
        if(a==b){cout<<0<<endl;continue;}
        int ans=0;
        int t=b;
        int flag=0;
        while(t!=1){
            if(fa[t]==a){ans+=mp[{t,fa[t]}];flag=1;break;}
            ans+=mp[{t,fa[t]}];
            t=fa[t];
        }
        if(flag)cout<<ans<<endl;
        else cout<<-1<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
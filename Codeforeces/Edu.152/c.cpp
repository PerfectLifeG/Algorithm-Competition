#include<bits/stdc++.h>
using namespace std;
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    int n,m;cin>>n>>m;
    string s;cin>>s;
    // cout<<s<<endl;
    vector<int>nxt(n+2,0),pre(n+2,0);
    nxt[n+1]=1e8;
    for(int i=n;i>=1;i--){
        nxt[i]=nxt[i+1];
        if(s[i-1]=='1')nxt[i]=i;
    }
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1];
        if(s[i-1]=='0')pre[i]=i;
    }
    // for(int i=1;i<=n;i++){
    //     cout<<i<<' '<<pre[i]<<" "<<nxt[i]<<endl;
    // }
    set<PII>ans;
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        // cout<<l<<' '<<r<<' ';
        l=nxt[l];r=pre[r];
        // cout<<l<<' '<<r<<endl;
        if(l>r){
            l=0;r=n+1;
        }

        // cout<<l<<' '<<r<<endl;
        // else if(nxt[l]<pre[r]){
        ans.insert({l,r});
        // }
    }
    cout<<ans.size()<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
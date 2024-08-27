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
    int n,s,k;cin>>n>>s>>k;
    if(2*k+1>n){
        cout<<-1<<endl;
        return;
    }
    vector<int>ans(n+1,1);
    if(k==0){
        ans[n]+=s-n;
    }
    else if(2*k+1<n){
        for(int i=0;i<=k;i++){
            ans[2*i+1]=2;
        }
        int t=3*k+2;
        t+=n-(2*k+2)+1;
        if(t>s){cout<<-1<<endl;return;}
        ans[2*k+2]+=s-t;
    }else{
        for(int i=0;i<=k;i++){
            ans[2*i+1]=2;
        }
        int t=3*k+2;
        if(t>s){cout<<-1<<endl;return;}
        int tt=(s-t)/(k+1);
        int ttt=(s-t)%(k+1);
        if(tt==0&&s>t){cout<<-1<<endl;return;}
        for(int i=0;i<=k;i++){
            ans[2*i+1]+=tt;
        }
        t+=tt*(k+1);
        // for(int i=1;i<=k;i++){
        //     int p=min(ttt,ans[2*k+1]-ans[2*k]-1);
        //     ans[2*k]+=p;
        //     ttt-=p;
        //     if(ttt==0)break;
        // }
        for(int i=2;i<=n;i+=2){
            if(tt<s){
                ans[i]++;
                tt++;
            }
        }
        // if(ttt>0){cout<<-1<<endl;return;}
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<' ';cout<<endl;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
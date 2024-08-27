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
const int INF=0x3f3f3f3f;
void solve(){
    int a,b,r;cin>>a>>b>>r;
    vector<int>v1(64);
    vector<int>v2(64);
    for(int i=0;i<60;i++){
        v1[i]=(a>>i)&1;
    }
    for(int i=0;i<60;i++){
        v2[i]=(b>>i)&1;
    }
    int flag=-1;
    int idx=0;
    vector<int>ans(64);
    for(int i=59;i>=0;i--){
        if(v1[i]!=v2[i]){
            if(v1[i]&&flag==-1){flag=1;idx=i;}
            else if(v2[i]&&flag==-1){flag=2;idx=i;}
        }else{
            v1[i]=0;
            v2[i]=0;
        }
        // cout<<b<<' '<<i<<' '<<v2[i]<<endl;
    }
    // cout<<flag<<' '<<idx<<endl;
    int t=0;
    if(flag==1){
        for(int i=0;i<60;i++){
            if(v1[i]&&idx!=i)ans[i]=1;
        }
    }else{
        for(int i=0;i<60;i++){
            if(v2[i]&&idx!=i)ans[i]=1;
            // if(ans[i])cout<<i<<' '<<ans[i]<<endl;
        }
    }
    for(int i=59;i>=0;i--){
        if(ans[i]&&(t+(1ll<<i))<=r)t+=(1ll<<i);
    }
    cout<<abs((a^t)-(b^t))<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
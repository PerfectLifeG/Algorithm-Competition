#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin()+1,x.end()
#define endl '\n'
const int N=200010;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
unordered_map<int,int>mp;
unordered_map<int,int>mp2;
int ksm(int a,int n){
    int r=1ll;
    while(n){
        if(n&1)r=r*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return r;
}
int inv(int a){
    return ksm(a,mod-2);
}
void solve(){
    int n,k;cin>>n>>k;
    int nx[n*30][2]={},val[n*30]={},idx=1;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(all(a));

    auto insert=[&](int x,int pos){
        int t=0;//初始为根节点0
        for(int i=30;i>=0;i--){
            int j=x>>i&1;
            if(!nx[t][j])nx[t][j]=idx++;
            t=nx[t][j];
            val[t]=(val[t]+mp2[pos])%mod;
        }
    };

    auto query=[&](int x){
        int t=0,res=0;
        for(int i=30;i>=0;i--){
            int j=x>>i&1;
            if(k>>i&1){
                if(nx[t][j])res=(res+val[nx[t][j]])%mod;
                if(nx[t][!j]){
                    t=nx[t][!j];
                }else return res;
            }else{
                if(nx[t][j]){
                    t=nx[t][j];
                }else return res;
            }
        }
        res=(res+val[t])%mod;
        return res;
    };

    int ans=0;
    for(int i=2;i<=n;i++){
        insert(a[i-1],i-1);
        ans=(ans+mp[i-1]*query(a[i])%mod)%mod;
    }
    cout<<(ans+n)%mod<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    int t=1;
    for(int i=0;i<=N;i++){
        mp[i]=t;
        mp2[i]=inv(t);
        t=t*2%mod;
    }
    while(_--)solve();
    return 0;
}
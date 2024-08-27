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
const int N=1e7+10;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;

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
int fac[N];
int ifac[N];
int C(int n,int m){
    if(m<0||n<m)return 0;
    return fac[n]*ifac[n-m]%mod*ifac[m]%mod;
}

void solve(){
    int n;cin>>n;
    int cnt=0;
    unordered_map<char,int>mp;
    for(int i=0;i<n;i++){
        char a;int b;
        cin>>a>>b;
        mp[a]=b;
        cnt+=b;
    }
    if(cnt%2==0){
        int flag=1;
        int res=fac[cnt/2];
        for(auto [a,b]:mp){
            if(b&1){flag=0;break;}
            res=res*C(b,b/2)%mod;
            res=res*fac[b/2]%mod;
        }
        if(flag){
            cout<<(1-res*inv(fac[cnt])%mod+mod)%mod*inv(2)%mod<<endl;
        }else cout<<inv(2)<<endl;
    }else{
        int ans=0;
        for(auto [a,b]:mp){
            int flag=1;
            int res=fac[(cnt-1)/2];
            for(auto [c,d]:mp){
                if(a==c)d--;
                if(d&1){flag=0;break;}
                res=res*C(d,d/2)%mod;
                res=res*fac[d/2]%mod;
            }
            if(flag){
                ans+=(res%mod+((fac[cnt-1]-res)%mod+mod)%mod*inv(2)%mod)%mod*b%mod;ans%=mod;
            }else {
                ans+=b*fac[cnt-1]%mod*inv(2)%mod;ans%=mod;
            }
        }
        cout<<ans*inv(fac[cnt])%mod<<endl;
    }

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int _=1;
    cin>>_;
    fac[0]=1;
    for(int i=1;i<N;i++){
        fac[i]=fac[i-1]*i%mod;
    }
    ifac[N-1]=inv(fac[N-1]);
    for(int i=N-1;i>=1;i--){
        ifac[i-1]=ifac[i]*i%mod;
    }
    while(_--)solve();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define x first
#define y second
typedef pair<int,int> PII;
const int N=1e5;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int ksm(int a,int n){
    int r=1ll;
    while(n){
        if(n&1)r=r*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return r;
}
void solve(){
    int n;cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<PII>v(n+1);
    for(int i=1;i<=n;i++){
        int mx=0;
        for(int j=i;j<=n;j+=i){
            mx=max(mx,a[j]);
        }
        v[i]={mx,i};
    }
    sort(v.begin()+1,v.end(),[&](PII a,PII b){
        return a.x<b.x;
    });
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=(ans+v[i].x*ksm(2,i-1)%mod)%mod;
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=1e9+7;
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
int inv(int a){
    return ksm(a,mod-2);
}
int b=1;
int C(int a,int c){
    if(a<c)return 0;
    int r=1ll;
    for(int i=a;i>a-c;i--){
        r=i%mod*r%mod;
    }
    return r*b%mod;
}
void solve()
{
    int n,m;cin>>n>>m;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        b=b*i%mod;
    }
    b=inv(b);
    int ans=C(n+m-1,n-1); 
    for(int i=1;i<1<<n;i++){
        int cnt=0;int t=0;
        for(int j=0;j<n;j++){
            if(i>>j&1){
                cnt++;
                t+=a[j]+1;
            }
        }
        if(cnt&1){
            ans=(ans-C(n+m-1-t,n-1)+mod)%mod;
        }else ans=(ans+C(n+m-1-t,n-1)+mod)%mod;
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    // cin>>_;
    while(_--)solve();
    return 0;
}
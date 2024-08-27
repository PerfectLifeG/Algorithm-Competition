#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl1
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=50010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int mo[N];
int prime[N],cnt;
int sum[N];
int book[N];
int mobius(int n){
    mo[1]=1;
    for(int i=2;i<=n;i++){
        if(!book[i]){
            prime[cnt++]=i;
            mo[i]=-1;
        }
        for(int j=0;prime[j]<=n/i;j++){
            book[prime[j]*i]=1;
            if(i%prime[j]==0){
                mo[prime[j]*i]=0;
                break;
            }
            mo[prime[j]*i]=-mo[i];
        }
    }
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+mo[i];
    }
}
int g(int n,int i){
    return n/(n/i);
}
void solve()
{
    int a,b,d;cin>>a>>b>>d;
    a/=d,b/=d;
    int ans=0;
    int n=min(a,b);
    for(int l=1,r;l<=n;l=r+1){
        r=min(n,min(g(a,l),g(b,l)));
        ans+=(sum[r]-sum[l-1])*(a/l)*(b/l);
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    mobius(N-1);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
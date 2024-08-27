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
const int N=5500;
int mod;
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
int C[N][N];
void init(){
    for(int i=0;i<N;i++){
        C[i][0]=1%mod;
        for(int j=1;j<=i;j++){
            C[i][j]=C[i-1][j]+C[i-1][j-1];
            C[i][j]%=mod;
        }
    }
}
void solve(){
    int n,m;cin>>n>>m>>mod;
    init();
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=C[n][i]*(ksm((ksm(2,i)-1+mod)%mod,(m-1+mod)%mod)%mod)%mod*ksm(2,(n-i)*(m-1)%mod)%mod;
        ans%=mod;
    }
    cout<<ans%mod<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int exgcd(int a,int b,int &x,int &y){
    if(b==0)return x=1,y=0,a;
    int d=exgcd(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-(a/b)*y;
    return d;
}
void solve(){
    int n,m;cin>>n>>m;
    int sum=0;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        sum+=a;
    }
    sum%=m;
    int s,d;
    int d1=exgcd(n%m,n*(n+1)/2%m,s,d);
    s%=m,d%=m;
    int k1,k2;
    int d2=exgcd(d1,m,k1,k2);
    int ans=sum%d2;
    cout<<ans<<endl;
    int k3=(ans-sum)/d2;

    k1=k1*k3%m;
    s=(s*k1%m+m)%m;
    d=(d*k1%m+m)%m;

    cout<<s<<' '<<d<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
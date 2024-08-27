#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
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
void solve()
{
    int m,k,a1,ak;
    cin>>m>>k>>a1>>ak;
    int x,y;
    int a=1,b=k,c=m;
    int d=exgcd(a,b,x,y);
    
    int b1=b/d;
    int x1=x*c/d;
    x1=(x1%b1+b1)%b1;
    int y1=(c-a*x1)/b;

    // cout<<x1<<' '<<y1<<endl;
    int t=max(0ll,(a1-x1)/k);
    ak+=t;
    int ans=max(0ll,x1-a1)+max(0ll,y1-ak);
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
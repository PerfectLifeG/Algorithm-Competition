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
int exgcd(int a,int b,__int128 &x,__int128 &y){
    if(b==0)return x=1,y=0,a;
    int d=exgcd(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-(a/b)*y;
    return d;
}
void solve(){
    int x1,x2,y1,y2;cin>>x1>>y1>>x2>>y2;
    if(x1==x2){
        cout<<x1+1<<' '<<y1<<endl;
        return;
    }
    if(y1==y2){
        cout<<x1<<' '<<y1+1<<endl;
        return;
    }
    int b=((x2-x1)*y1-x1*(y2-y1));
    int A=y2-y1;
    int B=x1-x2;
    // cout<<A<<' '<<B<<' '<<b<<endl;
    __int128 x,y;
    int d=exgcd(abs(A),abs(B),x,y);
    // cout<<d<<endl;
    __int128 k1=(-b+d-1)/d;
    if(k1*d+b==0)k1++;
    __int128 k2=(-b)/d;
    if(k2*d+b==0)k2--;
    // cout<<k1<<' '<<k2<<endl;
    __int128 k;
    __int128 aa=k1*d+b;
    if(aa<0)aa=-aa;
    __int128 bb=k2*d+b;
    if(bb<0)bb=-bb;

    if(aa<bb)k=k1;
    else k=k2;
    if(b==0)k=1;
    x=x*k;
    if(A<0)x=-x;
    y=y*k;
    if(B<0)y=-y;
    int kk=x/(-B);
    x=x%(-B);
    y=y-kk*A;
    cout<<(int)x<<' '<<(int)y<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
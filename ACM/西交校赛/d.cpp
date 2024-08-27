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
const int N=220;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
int g[N][N];
void solve(){
    int n;cin>>n;
    int l=INF,r=-INF,u=-INF,d=INF;
    int flag=0;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        if(a==0&&b==0)flag=1;
        a+=100,b+=100;
        g[a][b]=1;
        l=min(l,a);
        r=max(r,a);
        u=max(u,b);
        d=min(d,b);
    }
    if(!flag){cout<<-1<<endl;return;}
    // cout<<l<<' '<<r<<' '<<u<<' '<<d<<endl;
    for(int i=l;i<=r;i++){
        for(int j=d;j<=u;j++){
            if(!g[i][j]){cout<<-1<<endl;return;}
        }
    }
    cout<<r-l+u-d<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
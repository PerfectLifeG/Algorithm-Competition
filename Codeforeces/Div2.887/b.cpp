#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
#define x first
#define y second
PII f[N];
void solve()
{
    int n,k;cin>>n>>k;
    if(k>=2e5){
        cout<<0<<endl;
        return;
    }
    f[1]={1,0},f[2]={0,1};
    for(int i=3;i<=k;i++){
        f[i].x=f[i-1].x+f[i-2].x;
        f[i].y=f[i-1].y+f[i-2].y;
    }
    int a=f[k].x,b=f[k].y;
    int ans=0;
    for(int i=0;i<=n;i++){
        if((n-a*i)%b==0&&i<=(n-a*i)/b)ans++;
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
int a[N];
void solve()
{
    int n,p,x,q,y;
    cin>>n>>p>>x>>q>>y;
    int s=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        s+=a[i];
    }
    if(s%n==0){
        cout<<0<<endl;
        return;
    }
    int f1=-s%n,f2=n-s%n;
    int ans=f2*p;
    for(int i=1;i<n;i++){
        if((f1-y*i)%x==0)ans=min(ans,p*(f1-y*i)/x+i*q);
    }
    cout<<ans;
    // int ans2=1e18;
    // if(f1%y==0)ans2=q*f1/y;
    // ans2=min(ans2,q*(f1/y)+q+p*(y-(f1%y)));
    // cout<<min(f2*p,ans2);
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
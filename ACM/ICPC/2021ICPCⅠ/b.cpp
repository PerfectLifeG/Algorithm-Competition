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
int p;
void solve()
{
    double a,b,r;
    cin>>a>>b>>r;
    if(abs(b)<=r){
        printf("Case #%lld: %.2lf\n",p,2*a-r);
        return;
    }
    double ans=0;
    ans=2*sqrt(a*a+(abs(b)-r)*(abs(b)-r))-r;
    printf("Case #%lld: %.2lf\n",p,ans);
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    for(p=1;p<=_;p++)solve();
    return 0;
}
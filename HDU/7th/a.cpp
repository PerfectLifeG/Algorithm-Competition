#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    int x,a,b;cin>>x>>a>>b;
    int cnt=0;
    while(x)
    {
        int u=(x+a)/2;
        int v=sqrt(x+b);
        cnt++;
        if(x-1<u&&x-1<v)break;
    }
    cout<<cnt+x<<"\n";
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
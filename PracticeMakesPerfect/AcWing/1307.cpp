#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=5000011;
const int INF=0x3f3f3f3f;
int f[N],s[N];
void solve()
{
    int n,k;
    cin>>n>>k;
    s[0]=1;
    f[0]=1;
    for(int i=1;i<=n;i++){
        f[i]=s[max(i-k-1,0)];
        s[i]=(s[i-1]+f[i])%mod;
    }
    cout<<s[n];
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    // cin>>_;
    while(_--)solve();
    return 0;
}
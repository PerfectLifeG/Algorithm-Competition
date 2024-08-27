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
void _print(__int128 x)
{
    if(x > 9) _print(x/10);
    putchar(x%10 + '0');
}
void print(__int128 x)//输出
{
    if(x < 0)
    {
        x = -x;
        putchar('-');
    }
    _print(x);
}
void solve()
{
    int n;cin>>n;
    vector<int>s(n+1);
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    __int128 ans=0;
    for(int i=1;i<=n;i++){
        ans+=__int128(a[i]*(s[n]-s[i]));
    }
    print(ans);
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
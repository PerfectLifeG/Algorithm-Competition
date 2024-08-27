#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
inline int Log2(double x){
    if(x==1)return 0;
    return ((*(unsigned long long*)&x>>52)&1023)+1;
}
void solve()
{
    int n;cin>>n;
    int a=Log2(n);
    if(1<<a!=n)cout<<a+1<<endl;
    else cout<<a<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
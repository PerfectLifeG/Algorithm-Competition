#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    int x,y,z;cin>>x>>y>>z;
    if(z==0&&(x==0||y==0)){
        yes;
        return;
    }else if(z==0){
        no;
        return;
    }
    int t=__gcd(x,y);
    if(z%t==0){
        yes;
    }else no;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
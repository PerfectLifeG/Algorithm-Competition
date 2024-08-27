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
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int n;
int f(int i){
    return (n/i)+i-1;
}
void solve(){
    int a,b;cin>>n>>a>>b;
    int t=1e18;
    for(int i=max(1ll,(int)sqrt(n)-100);i<(int)sqrt(n)+100;i++){
        if(f(i)<f(t))t=i;
    }
    if(a>t){cout<<a<<endl;return;}
    int l=a-1,r=min(b,t);
    int x=f(r);
    while(l+1<r){
        int mid=l+r>>1;
        if(f(mid)>x){
            l=mid;
        }else r=mid;
    }
    cout<<r<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
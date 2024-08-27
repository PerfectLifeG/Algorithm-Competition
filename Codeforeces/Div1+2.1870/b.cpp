#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n,k,x;cin>>n>>k>>x;
    if(x<k-1){
        cout<<-1<<endl;
        return;
    }
    if(n<k){
        cout<<-1<<endl;
        return;
    }
    int ans=0,t=0;
    if(x>k)ans=k*(k-1)/2,t+=k;
    else if(x<k)ans=x*(x-1)/2,t+=x;
    else ans=ans=k*(k-1)/2,t+=k;
    t=n-t;
    if(x==k)
        ans+=t*(x-1);
    else 
    ans+=t*x;
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
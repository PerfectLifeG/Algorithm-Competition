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
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int t,a,k;cin>>t>>a>>k;
    if(a*t>=0){
        if(abs(a)<=abs(t))cout<<abs(t);
        else cout<<abs(t)+2*(abs(a)-abs(t))<<endl;
    }else{
        if(a>=-k&&a<=k){
            cout<<abs(a)*2+abs(t)<<endl;
        }else cout<<abs(t)+2*abs(t-a)<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
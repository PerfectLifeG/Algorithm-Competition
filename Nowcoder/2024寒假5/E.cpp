#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n;cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n%2==0||n==1){
        yes;return;
    }
    int mx=0;
    for(int i=n-1;i>=1;i--){
        if(i%2==0){
            mx=max(mx,(a[i+1]-a[i])/i);
            a[i-1]+=mx*(i-1);
            a[i]+=mx*i;
        }
    }
    for(int i=1;i<=n-1;i++){
//         cout<<a[i]<<' ';
        if(a[i]>a[i+1]){no;return;}
    }
    yes;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
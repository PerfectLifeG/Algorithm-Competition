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
    int n,m;cin>>n>>m;
    vector<int>a(n+1);
    vector<int>b(m+1);
    int t=0;
    int mx=0;
    int mn=1e18;
    for(int i=0;i<n;i++){
        cin>>a[i];
        t^=a[i];
    }
    // 01
    // 10

    // 11

    // 11

    // 01

    // 10
    // 11
    // 10

    int tt=t;
    for(int i=0;i<m;i++){
        cin>>b[i];
        if(n%2==0){mn=min(mn,~b[i]&t);t=~b[i]&t;}
        else {mx=max(mx,b[i]|t);t|=b[i];}
    }
    if(n%2==0){
        cout<<mn<<' '<<tt<<endl;
    }else cout<<tt<<' '<<mx<<endl;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
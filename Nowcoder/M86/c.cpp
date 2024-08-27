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
void solve(){
    int n,m;cin>>n>>m;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<int>f(n+1);
    f[1]=1;
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1]){
            f[i]=f[i-1];
        }else f[i]=f[i-1]+1;
    }
    while(m--){
        int c,b;cin>>c>>b;
        cout<<f[b]-f[c-1]+(int)(a[c]==a[c-1])<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
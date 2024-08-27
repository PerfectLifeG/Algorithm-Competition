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
    int n,k;cin>>n>>k;
    string s;cin>>s;
    s=' '+s;
    vector<int>a(k+1);
    vector<int>b(k+1);
    for(int i=1;i<=k;i++){
        cin>>a[i];
    }
    for(int i=1;i<=k;i++){
        cin>>b[i];
    }
    int q;cin>>q;
    vector<int>c(n+10);
    while(q--){
        int x;cin>>x;
        int t=prev(upper_bound(a.begin()+1,a.begin()+1+k,x))-a.begin();
        int l=min(x,a[t]+b[t]-x);
        int r=max(x,a[t]+b[t]-x);
        c[l]+=1;
        c[r+1]-=1;
    }
    for(int i=1;i<=n;i++){
        c[i]+=c[i-1];
    }
    for(int i=1;i<=k;i++){
        int t=a[i];
        while(t<=(b[i]+a[i])/2){
            if(c[t]&1){
                swap(s[t],s[b[i]-(t-a[i])]);
                // cout<<t<<' '<<b[i]-(t-a[i])<<endl;
            }
            t++;
        }
    }
    cout<<string(s.begin()+1,s.end())<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
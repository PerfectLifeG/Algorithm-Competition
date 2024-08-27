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
    int n;cin>>n;
    vector<int>a(n+1);
    vector<int>v;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)v.push_back(i);
    }
    vector<int>pre(n+1);
    vector<int>mul(n+1);
    mul[0]=1;
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
        mul[i]=mul[i-1]*a[i];
        if(mul[i]>=(1<<19)||mul[i]<0){
            cout<<v[0]<<' '<<v.back()<<endl;
            return;
        }
    }
    if(v.size()>=18){
        cout<<v[0]<<' '<<v.back()<<endl;
        return;
    }
    // for(auto i:v)cout<<i<<' ';cout<<endl;
    int ans1=1,ans2=1;
    int mx=1;
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            if(mul[v[j]]/mul[v[i]-1]-pre[v[j]]+pre[v[i]-1]>=mx){
                mx=mul[v[j]]/mul[v[i]-1]-pre[v[j]]+pre[v[i]-1];
                ans1=v[i],ans2=v[j];
            }
        }
    }
    cout<<ans1<<' '<<ans2<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
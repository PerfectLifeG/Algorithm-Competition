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
    int id=1;
    vector<int>mp(k+1);
    vector<int>mp2(k+1);
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        while(id<=a[i])mp[id++]=i;
    }
    vector<int>v(k+1,0);
    id=1;
    for(int i=n;i>=1;i--){
        while(id<=a[i])mp2[id++]=i;
    }
    // for(int i=1;i<=k;i++){cout<<i<<' '<<mp[i]<<' '<<mp2[i]<<endl;}
    for(int i=n;i>=1;i--){
        if(v[a[i]])continue;
        v[a[i]]=(mp2[a[i]]-mp[a[i]]+1)*2;
    }
    for(int i=1;i<=k;i++){
        cout<<v[i]<<' ';
    }
    cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
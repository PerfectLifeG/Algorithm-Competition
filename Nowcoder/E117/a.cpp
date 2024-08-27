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
    int n;cin>>n;
    int mn=1e18,mx=0;
    int mn2=1e18,mx2=0;
    vector<int>v(n);
    int s=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        s+=v[i];
        if(mn>v[i]){
            mn2=min(mn2,mn);
            mn=min(mn,v[i]);
        }else mn2=min(mn2,v[i]);
        if(mx<v[i]){
            mx2=max(mx,mx2);
            mx=max(mx,v[i]);
        }else mx2=max(mx2,v[i]);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(v[i]+1>mx){
            ans=max(ans,s-v[i]-mn);
        }
        else if(v[i]==mn){
            ans=max(ans,s-mx-min(mn2,v[i]+1));
        }
        else{
            ans=max(ans,s-mn-mx+1);
        }
    }
    cout<<max(ans,s-mx-mn)<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
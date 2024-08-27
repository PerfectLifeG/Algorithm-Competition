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
    vector<int>p;
        int l=-1,r=1e18;
    for(int i=0;i<n;i++){
        int op;int a;cin>>op>>a;
        if(op==1){
            l=max(a,l);
        }
        else if(op==2){
            r=min(r,a);
        }else{
            p.push_back(a);
        }
    }
    if(l>r){
        cout<<0<<endl;
        return;
    }
    int ans=r-l+1;
    for(auto i:p){
        if(i>=l&&i<=r){
            ans--;
        }
    }
    cout<<max(0ll,ans)<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
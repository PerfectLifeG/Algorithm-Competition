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
    int n;cin>>n;
    vector<int>a(n);
    vector<int>pre(n);
    vector<int>suf(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    pre[0]=a[0];
    for(int i=1;i<n;i++){
        pre[i]=max(pre[i-1],a[i]);
    }
    suf[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--){
        suf[i]=min(suf[i+1],a[i]);
    }
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(a[i]>=pre[i]&&a[i]<=suf[i]){
            ans.push_back(a[i]);
        }
    }
    cout<<ans.size()<<endl;
    if(ans.size()){
        cout<<ans[0];
    }
    for(int i=1;i<ans.size();i++)cout<<' '<<ans[i];
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
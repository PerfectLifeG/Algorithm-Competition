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
    vector<int>v(n);
    vector<int>book(n);
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        sum+=v[i];
    }
    int ans=1e18;
    function<void(int,int)> dfs=[&](int t,int p){
        if(t==v.size()){
            ans=min(ans,abs((sum-p)-p));
            return;
        }
        for(int i=t;i<v.size();i++){
            if(book[i])continue;
            book[i]=1;
            dfs(i+1,p+v[i]);
            book[i]=0;
        }
    };
    dfs(0,0);
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
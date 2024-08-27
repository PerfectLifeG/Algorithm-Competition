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
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>ans(n);
    for(int i=0;i<n;i++){
        if(a[i]!=a[i-1])ans[i]=i-1;
        else ans[i]=ans[i-1];
    }
    int q;cin>>q;
    while(q--){
        int a,b;cin>>a>>b;a--,b--;
        if(ans[b]>=a){
            cout<<ans[b]+1<<' '<<b+1<<endl;
        }else cout<<-1<<' '<<-1<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
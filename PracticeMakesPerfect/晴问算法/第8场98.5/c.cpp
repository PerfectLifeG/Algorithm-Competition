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
int ans=INF;
int n;
int v[13];
int a[13];
void dfs(int t,int id){
    if(t==n){
        int mx=0;
        for(int i=0;i<=id;i++){
            mx=max(mx,abs(v[i]));
        }
        ans=min(ans,mx);
        return;
    }
    v[id+1]+=a[t];
    dfs(t+1,id+1);
    v[id+1]-=a[t];
    for(int i=0;i<=id;i++){
        v[i]+=a[t];
        dfs(t+1,id);
        v[i]-=a[t];
    }
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    dfs(0,-1);
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
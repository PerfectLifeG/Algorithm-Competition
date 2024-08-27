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
const int N=550;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int f[N];
int n,c;
void solve(){
    cin>>n>>c;
    vector<int>v(n);
    for(int i=0;i<=c;i++){
        f[i]=0;
    }
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(all(v));
    int ans=1e9;
    for(int i=0;i<n;i++){
        for(int j=c;j>=v[i];j--){
            if(j==v[i])f[j]=j;
            if(f[j-v[i]])f[j]=max(f[j],f[j-v[i]]);
        }
        if(f[c])ans=min(ans,v[i]-f[c]);
    }
    if(ans>=500)cout<<-1<<endl;
    else cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
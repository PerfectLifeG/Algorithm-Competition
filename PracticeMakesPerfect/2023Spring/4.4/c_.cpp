#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200010;
const int mod=998244353;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
int a[N];
int ans[N];
void solve(){
    int n;cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>a[i];
    }
    memset(ans,0,sizeof ans);
    ans[n-1]=a[n-2];
    for(int i=n-3,j=n-2;j>=0&&i>=0;j--,i--){
        if(a[i+1]>=a[i])ans[j]=a[i];
        else {ans[j--]=0;ans[j]=a[i];}
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
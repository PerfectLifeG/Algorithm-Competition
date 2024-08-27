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
    ans[0]=a[0];
    a[n-1]=1e9+10;
    int flag=1;
    for(int i=1,j=1;j<n;i++,j++){
        if(flag){
            if(ans[j-1]>=a[i]){ans[j]=a[i];}
            else {ans[j]=0;i--;flag=0;}
        }
        else {
            if(ans[j-1]>a[i])ans[j]=0;
            else ans[j]=min(a[i],a[i+1]);
        }
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
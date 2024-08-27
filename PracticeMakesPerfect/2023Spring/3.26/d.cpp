#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=300010;
const int mod=998244353;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
int a[N];
int s[N];
void solve(){
    int n;cin>>n;
    int mx=0,mn=1e9;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
        mn=min(mn,a[i]);
        s[i]=a[i]+s[i-1];
    }
    if(abs(s[n])>=mx-mn){
        no;return;
    }
    sort(a+1,a+1+n);
    int i=1,j=n;
    int ans[n+1];
    int idx=1;
    int s=0;
    while(i<=j){
        if(abs(s+a[j])<mx-mn&&abs(s+a[j]+a[i])<mx-mn){
            ans[idx++]=a[j];
            s+=a[j];
            j--;
        }else{
            ans[idx++]=a[i];
            s+=a[i];
            i++;
        }
    }
    yes;
    for(int i=1;i<=n;i++){
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
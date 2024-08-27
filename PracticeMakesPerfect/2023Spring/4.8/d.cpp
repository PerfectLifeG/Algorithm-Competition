#include<bits/stdc++.h>
using namespace std;
const int N=1010;
const int mod=998244353;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
int a[N];
int ans[N];
int ans2[N];
int sub[N];
void solve(){
    int n;cin>>n;
    int re;
    cout<<"+ "<<n<<endl;
    cin>>re;
    cout<<"+ "<<n+1<<endl;
    cin>>re;
    int mx=0,idx;
    for(int i=2;i<=n;i++){
        cout<<"? "<<1<<' '<<i<<endl;
        cin>>a[i];
        if(mx<a[i]){
            mx=a[i];
            idx=i;
        }
    }
    ans[idx]=n;
    ans2[idx]=(n+1)/2;
    for(int i=1;i<=n-1;i++){
        if(i%2==0)sub[i]=-sub[i-1];
        else sub[i]=(i+1)/2;
    }
    for(int i=1;i<=n;i++){
        if(i==idx)continue;
        cout<<"? "<<idx<<' '<<i<<endl;
        int t;
        cin>>t;
        ans[i]=(sub[t]+ans[idx]+n)%n;
        if(n&1)ans2[i]=-sub[t]+ans2[idx];
        else ans2[i]=sub[t]+ans2[idx];
    }
    cout<<"!";
    for(int i=1;i<=n;i++){
        cout<<' '<<ans[i];
    }
    for(int i=1;i<=n;i++){
        cout<<' '<<ans2[i];
    }
    cout<<endl;
    cin>>re;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
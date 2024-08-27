#include<bits/stdc++.h>
using namespace std;
const int N=100;
const int mod=998244353;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
void solve(){
    int n,k;
    cin>>n>>k;
    int ans[N];int t=n;int cnt=0;
    if(k<=n){
        ans[0]=100;
        for(int i=1;i<=k-1;i++){
            ans[i]=-1;
        }
        for(int i=k;i<n;i++){
            ans[i]=-999;
        }
    }
    else{
        while(k>=t&&k){
            ans[cnt++]=100;
            k-=t;
            t--;
        }
        for(int i=cnt;i<n;i++)ans[i]=-2;
        ans[cnt]=2*(k-1)+1;
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
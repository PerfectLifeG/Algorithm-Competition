#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200010;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
int a[N];
int s[N];
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    if(a[1]!=1){no;return;}
    for(int i=1;i<=n;i++)s[i]=a[i]+s[i-1];
    for(int i=2;i<=n;i++){
        if(a[i]>s[i-1]){
            no;
            return;
        }
    }
    yes;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
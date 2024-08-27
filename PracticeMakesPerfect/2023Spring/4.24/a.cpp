#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
int a[N],b[N];
void solve(){
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]+=i-1;
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    int idx=-1,mx=0;
    for(int i=1;i<=n;i++){
        if(q>=a[i]&&mx<b[i]){
            idx=i;
            mx=b[i];
        }
    }
    cout<<idx<<endl;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
int a[N];
void solve(){
    int n,x,y;cin>>n>>x>>y;
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>y)ans+=3;
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    while(T--){
        solve();
    }
    return 0;
}
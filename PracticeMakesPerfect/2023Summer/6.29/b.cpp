#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200010;
const int mod=998244353;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
void solve(){
    int x1,x2,x3,y1,y2,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    int ans=0;
    if(x1<x2&&x1<x3||x1>x2&&x1>x3){
        ans+=min(abs(x1-x2),abs(x1-x3))+1;
    }else ans+=1;
    if(y1<y2&&y1<y3||y1>y2&&y1>y3){
        ans+=min(abs(y1-y2),abs(y1-y3))+1;
    }else ans+=1;
    cout<<ans-1<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
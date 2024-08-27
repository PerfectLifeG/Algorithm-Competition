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
void solve(){
    int n,m;cin>>n>>m;
    set<int>s;
    int l=0,r=0;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        if(a==-1)l++;
        if(a==-2)r++;
        if(a>0)s.insert(a);
    }
    int cnt=m-s.size();
    int ans=0;
    int now=0;int t=1;
    for(auto i:s){
        now+=i-t;
        int tt=0;
        if(l>now){
            tt+=now;
        }else tt+=l;
        if(r>cnt-now)tt+=cnt-now;
        else tt+=r;
        ans=max(ans,tt);
        t=i+1;
    }
    int b=min(r,cnt)+s.size();
    int c=min(l,cnt)+s.size();
    b=max(b,c);
    int d=ans+s.size();
    cout<<max(b,d)<<endl;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
void solve(){
    int n;cin>>n;
    int a,b,c,d;cin>>a>>b>>c>>d;
    if(a>n/2)a=n-a+1;
    if(b>n/2)b=n-b+1;
    if(c>n/2)c=n-c+1;
    if(d>n/2)d=n-d+1;
    int t1=min(a,b),t2=min(c,d);
    cout<<abs(t1-t2)<<endl;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
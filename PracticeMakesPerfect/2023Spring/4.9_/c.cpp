#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
void solve(){
    int n,m;cin>>n>>m;
    int a,b,c;
    cout<<'?'<<' '<<n<<' '<<m<<endl;
    cin>>a;
    int flag=0;
    if(a==0){cout<<'!'<<' '<<n<<' '<<m<<endl;return;}
    
    if(n-a<=0){cout<<'?'<<' '<<n<<' '<<m-a<<endl;flag=1;}
    else cout<<'?'<<' '<<n-a<<' '<<m<<endl;
    
    cin>>b;
    if(b==0&&flag){cout<<'!'<<' '<<n<<' '<<m-a<<endl;return;}
    if(b==0){cout<<'!'<<' '<<n-a<<' '<<m<<endl;return;}
    if(flag)cout<<'?'<<' '<<n-b<<' '<<m-a<<endl;
    else cout<<'?'<<' '<<n-a<<' '<<m-b<<endl;
    
    cin>>c;
    if(flag){cout<<'!'<<' '<<n-b<<' '<<m-a+c<<endl;return;}
    else {cout<<'!'<<' '<<n-a+c<<' '<<m-b<<endl;return;}
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
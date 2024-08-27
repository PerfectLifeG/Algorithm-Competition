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
    int flag=0;
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        if(!flag&&a<=i){
            yes;
            flag=1;
        }
    }
    if(flag)return;
    no;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
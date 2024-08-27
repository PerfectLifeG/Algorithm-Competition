#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define all(x) x.begin(),x.end()
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl
typedef pair<int,int> PII;
void solve(){
    int x;cin>>x;
    // if(x==1||x==2){
    //     cout<<x<<endl;
    //     return;
    // }
    for(int i=1;i<=x;i++){
        if(x-i>i){cout<<i<<' ';x-=i;}
        if(x-i==0){cout<<i<<' ';break;}
    }
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
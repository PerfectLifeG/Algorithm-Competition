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
    int n;cin>>n;
    int ans=0;
    int s=1;
    int sum=0;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        s*=a;
        sum+=a;
    }
    if(sum>=0&&s==1){
        cout<<0<<endl;
        return;
    }
    if(sum>=0&&s==-1){
        cout<<1<<endl;
        return;
    }
    if(sum<0&&s==1){
        int t=((0-sum)+1)/2;
        if(t&1)
        cout<<t+1<<endl;
        else cout<<t<<endl;
        return;
    }
    if(sum<0&&s==-1){
        int t=((0-sum)+1)/2;
        if(t&1)cout<<t<<endl;
        else cout<<t+1<<endl;
        return;
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
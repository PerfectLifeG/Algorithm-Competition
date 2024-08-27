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
    string a,b;cin>>a>>b;
    int ans=0;
    int f1=0,f2=0;
    for(int i=0;i<n;i++){
        if(a[i]!=b[i])f1++;
        if(a[i]!=b[n-i-1])f2++;
    }
    if(f1<=1){
        cout<<f1<<endl;
        return;
    }
    if(f2==0){
        cout<<2<<endl;
        return;
    }
    if(f1%2==0&&f2&1)cout<<min(f1*2,f2*2)<<endl;
    else if(f1%2==0&&f2%2==0)cout<<min(f1*2,f2*2-1)<<endl;
    else if(f1%2&1&&f2&1)cout<<min(f1*2-1,f2*2)<<endl;
    else cout<<min(f1*2-1,f2*2-1)<<endl;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
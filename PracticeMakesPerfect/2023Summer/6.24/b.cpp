#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
const int N=100010;
const int mod=998244353;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
int a[N];
// 0110
// 0101
// 0111
// 0010
void solve(){
    int n,x;cin>>n>>x;
    int ans=0;
    int f=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(f&&(a[i]|x)==x&&(a[i]&x)<=x)ans|=a[i];
        else {f=0;}
    }
    f=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(f&&(a[i]|x)==x&&(a[i]&x)<=x)ans|=a[i];
        else {f=0;}
    }
    f=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(f&&(a[i]|x)==x&&(a[i]&x)<=x)ans|=a[i];
        else {f=0;}
    }
    if(ans==x){
        yes;
    }
    else no;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
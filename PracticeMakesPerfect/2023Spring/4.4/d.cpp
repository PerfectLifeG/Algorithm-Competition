#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
int f[N];
int check(int n,int x,int y){
    if(n==1&&(x==1&&y==1||x==2&&y==1)){
        return 1;
    }
    if(f[n-1]<x&&x<=f[n]){
        return 0;
    }
    if(f[n]<x){
        x-=f[n];
    }
    return check(n-1,y,x);
}
void solve(){
    int n,x,y;cin>>n>>x>>y;
    x=f[n]-x+1;
    if(check(n,y,x)){
        yes;
    }else no;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    f[0]=1;f[1]=1;
    for(int i=2;i<=44;i++){
        f[i]=f[i-1]+f[i-2];
    }    
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
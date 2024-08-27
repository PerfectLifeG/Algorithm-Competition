#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
int a[N],b[N];
void solve(){
    int n;cin>>n;
    int mxa=0,mxb=0;
    int flag1,flag2;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]<b[i])swap(a[i],b[i]);
    }
    for(int i=0;i<n;i++){
        if(mxb<=b[i]){
            flag2=i;
            mxb=b[i];
        }
        if(mxa<=a[i]){
            flag1=i;
            mxa=a[i];
        }
    }
    if(flag1==flag2&&flag1==n-1)yes;
    else no;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
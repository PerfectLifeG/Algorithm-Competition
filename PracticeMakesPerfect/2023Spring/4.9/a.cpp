#include<bits/stdc++.h>
using namespace std;
const int N=1010;
const int mod=998244353;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
int g[N][N];
void solve(){
    int n,k;cin>>n>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>g[i][j];
        }
    }
    int cnt=0;
    int flag=1;
    for(int i=0;i<n/2;i++){
        if(cnt>k){flag=0;break;}
        for(int j=0;j<n;j++){
            // if(i==1&&j==1)cout<<(g[1][1]^g[2][2])<<endl;
            cnt+=(g[i][j]^g[n-i-1][n-j-1]);
            // cout<<cnt;
        }
    }
    if(n&1){
        for(int j=0;j<n/2;j++){
            if(cnt>k){flag=0;break;}
            cnt+=(g[(n-1)/2][j]^g[(n-1)/2][n-j-1]);
        }
    }
    if(cnt>k){flag=0;}
    else if(!(n&1)&&(k-cnt)%2!=0)flag=0;
    if(flag){
        yes;
    }else no;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
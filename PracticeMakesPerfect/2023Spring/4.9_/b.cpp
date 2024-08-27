#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
int b[3][N];
void solve(){
    int n;cin>>n;
    if(n&1){
        for(int i=1;i<=n;i++){
            b[1][i]=2*n-i+1;
        }
        for(int i=1;i<=n;i++){
            b[2][i]=i;
        }
        for(int i=1;i<=n;i++){
            if(i&1)cout<<b[1][i]<<' ';
            else cout<<b[2][i]<<' ';
        }
        cout<<endl;
        for(int i=1;i<=n;i++){
            if(i&1)cout<<b[2][i]<<' ';
            else cout<<b[1][i]<<' ';
        }
        cout<<endl;
        return;
    }
    else {
        for(int i=1;i<=n;i+=2){
            b[1][i]=2*n-i+1;
            b[1][n-i+1]=2*n-i;
        }
        for(int i=1;i<=n;i++){
            b[2][i]=i;
        }
        for(int i=1;i<=n;i++){
            if(i&1)cout<<b[1][i]<<' ';
            else cout<<b[2][i]<<' ';
        }
        cout<<endl;
        for(int i=1;i<=n;i++){
            if(i&1)cout<<b[2][i]<<' ';
            else cout<<b[1][i]<<' ';
        }
        cout<<endl;
        return ;
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
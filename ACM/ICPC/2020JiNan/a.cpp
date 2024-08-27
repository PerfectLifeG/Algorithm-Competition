#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=6;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int A[N][N];
int B[N][N];
int C[N][N];
int D[N][N];
int n;
int ans=0;
int check(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            D[i][j]=0;
            for(int k=0;k<n;k++){
                D[i][j]+=A[i][k]*C[k][j];
            }
            D[i][j]%=2;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(B[i][j]*C[i][j]!=D[i][j]){
                return 0;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<C[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
    return 1;
}
void dfs(int t){
    if(t==n*n){
        if(check()){
            ans++;
        }
        return;
    }
    C[t/n][t%n]=1;
    dfs(t+1);
    C[t/n][t%n]=0;
    dfs(t+1);
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>A[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>B[i][j];
        }
    }
    dfs(0);
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
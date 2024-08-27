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
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n,m,x;cin>>n>>m>>x;
    int g[n][m]={};
    if(x==2){cout<<-1<<endl;return;}
    else if(x%4==0){
        g[1][1]=g[1][2]=g[2][1]=g[2][2]=x/4;
    }
    else if(x%4==2){
        g[1][1]=g[1][2]=g[2][1]=g[2][3]=g[3][2]=g[3][3]=1;
        g[2][2]=g[2][4]=g[4][2]=g[4][4]=(x-6)/4;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<g[i][j]<<' ';
        }cout<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
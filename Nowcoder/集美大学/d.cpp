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
const int INF=0x3f3f3f3f;
int g[13][13];
int col[13];
int row[13];
int ans=0;
void dfs(int now,int cnt){
    if(cnt==13){
        ans=max(ans,now);
        return;
    }
    for(int i=0;i<13;i++){
        if(row[i])continue;
        for(int j=0;j<13;j++){
            if(col[j])continue;
            row[i]=1;
            col[j]=1;
            dfs(now+g[i][j],cnt+1);
            row[i]=0;
            col[j]=0;
        }
    }
}
void solve(){
    for(int i=0;i<13;i++){
        for(int j=0;j<13;j++){
            cin>>g[i][j];
        }
    }
    dfs(0,0);
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
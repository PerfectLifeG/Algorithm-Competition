#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
#define x first
#define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
int dir[4][2]={0,1,0,-1,1,0,-1,0};
void solve(){
    int n,m;cin>>n>>m;
    int g[n][m]={};
    int book[n][m]={};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
        }
    }   
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]==0)continue;
            if(!book[i][j]){
                queue<PII>q;
                q.push({i,j});
                book[i][j]=1;
                int tmp=0;
                int flag=0;
                while(q.size()){
                    auto t=q.front();
                    if(g[t.x][t.y]==-1)flag=1;
                    tmp+=g[t.x][t.y];
                    q.pop();
                    for(int k=0;k<4;k++){
                        int tx=t.x+dir[k][0],ty=t.y+dir[k][1];
                        if(tx<0||ty<0||tx>=n||ty>=m||book[tx][ty]||g[tx][ty]==0)continue;
                        book[tx][ty]=1;
                        q.push({tx,ty});
                    }
                }
                if(!flag)ans=max(ans,tmp);
            }
        }
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
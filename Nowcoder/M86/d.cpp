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
const int N=1010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int n,m;
char g[N][N];
int book[N][N];
int dir[4][2]={-1,0,1,0,0,-1,0,1};
int bfs(int a,int b){
    queue<PII>q;
    q.push({a,b});
    book[a][b]=1;
    PII t1={a,b},t2={a,b},t3={a,b},t4={a,b};
    int x1=a,x2=a,y1=b,y2=b;
    int sum=1;
    while(q.size()){
        auto t=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int tx=t.x+dir[i][0],ty=t.y+dir[i][1];
            // cout<<t.x<<' '<<t.y<<' '<<tx<<' '<<ty<<endl;
            if(tx<0||tx>=n||ty<0||ty>=m||g[tx][ty]=='*'||book[tx][ty])continue;
            book[tx][ty]=1;
            x1=min(x1,tx);
            x2=max(x2,tx);
            y1=min(y1,ty);
            y2=max(y2,ty);
            q.push({tx,ty});
            sum++;
            if(i==0){
                if(tx<=t1.x&&t1.y>=ty){
                    t1={tx,ty};
                }
                if(tx<=t2.x&&t2.y<=ty){
                    t2={tx,ty};
                }
            }else if(i==1){
                if(tx>=t3.x&&t3.y>=ty){
                    t3={tx,ty};
                }
                if(tx>=t4.x&&t4.y<=ty){
                    t4={tx,ty};
                }
            }else if(i==2){
                if(tx<=t1.x&&t1.y>=ty){
                    t1={tx,ty};
                }
                if(tx>=t3.x&&t3.y>=ty){
                    t3={tx,ty};
                }
            }else{
                if(tx>=t4.x&&t4.y<=ty){
                    t4={tx,ty};
                }
                if(tx<=t2.x&&t2.y<=ty){
                    t2={tx,ty};
                }
            }
        }
    }
    if(sum==(abs(x2-x1)+1)*(abs(y2-y1)+1)&&t1.x==x1&&t2.x==x1&&t3.x==x2&&t4.x==x2&&t1.y==y1&&t3.y==y1&&t2.y==y2&&t4.y==y2){
        return 1;}
    else return 0;
}
void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        for(int j=0;j<s.size();j++){
            g[i][j]=s[j];
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!book[i][j]&&g[i][j]=='.')
                if(bfs(i,j))ans++;
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
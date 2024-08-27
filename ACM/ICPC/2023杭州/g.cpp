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
const int INF=1e18;
char g[3030][3030];
int book[3030][3030];
int book2[3030][3030];
int d[3030][3030];
int dir[4][2]={1,0,-1,0,0,1,0,-1};
void solve(){
    priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>>pq;
    int n,m,k;cin>>n>>m>>k;
    for(int i=0;i<3030;i++)for(int j=0;j<3030;j++)d[i][j]=INF;
    // PII st;
    for(int i=1;i<=k;i++){
        int a,b;cin>>a>>b;
        if(i==1){
            pq.push({0,a,b});
            // book[a][b]=0;
            d[a][b]=0;
        }
        // if(i==2){st.x=a;st.y=b;}
        book2[a][b]=k-i;
    }
    for(int i=1;i<=n;i++){
        string s;cin>>s;
        for(int j=1;j<=m;j++){
            g[i][j]=s[j-1];
        }
    }

    deque<array<int,3>>q;
    auto check=[&](){
        if(pq.empty())return;
        if(q.empty()){
            q.push_back(pq.top());
            pq.pop();
        }else if(pq.top()[0]<=q.front()[0]){
            q.push_front(pq.top());
            pq.pop();
        }
    };

    while(q.size()||pq.size()){
        check();
        auto [w,x,y]=q.front();
        q.pop_front();
        if(book[x][y])continue;
        book[x][y]=1;
        // cout<<w<<' '<<x<<' '<<y<<endl;
        for(int i=0;i<4;i++){   
            int tx=x+dir[i][0],ty=y+dir[i][1];
            // cout<<tx<<' '<<ty<<' '<<book[tx][ty]<<' '<<g[tx][ty]<<' '<<book[x][y]<<' '<<book2[tx][ty]<<endl;
            if(tx<=0||ty<=0||tx>n||ty>m||book[tx][ty]||g[tx][ty]=='#')continue;
            // cout<<tx<<' '<<ty<<' '<<book2[tx][ty]<<endl;
            if(d[x][y]<book2[tx][ty]){
                if(d[tx][ty]>book2[tx][ty]+1){
                    d[tx][ty]=book2[tx][ty]+1;
                    pq.push({d[tx][ty],tx,ty});
                }
            }else if(d[tx][ty]>d[x][y]+1){
                d[tx][ty]=d[x][y]+1;
                q.push_back({d[tx][ty],tx,ty});
            }
        }
    }
    unsigned long long ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(d[i][j]==INF)continue;
            // cout<<d[i][j]<<' ';
            ans+=d[i][j]*d[i][j];
        }
        // cout<<endl;
    }
    cout<<ans<<endl;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
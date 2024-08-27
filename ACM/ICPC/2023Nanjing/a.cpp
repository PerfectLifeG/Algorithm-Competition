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
    char g[n][m];
    PII book[n][m]={};
    int book2[n][m]={};int idx=1;
    int sum=0;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        for(int j=0;j<m;j++){
            g[i][j]=s[j];
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!book2[i][j]&&g[i][j]=='.'){
                idx++;
                queue<PII>q;
                q.push({i,j});
                book[i][j]={0,0};
                book2[i][j]=idx;
                vector<PII>v;
                int cnt=0;
                while(q.size()){
                    auto t=q.front();
                    q.pop();
                    cnt++;
                    for(int k=0;k<4;k++){
                        int x=t.x+dir[k][0],y=t.y+dir[k][1];
                        if(x<0||y<0||x>=n||y>=m||book2[x][y]||g[x][y]=='O')continue;
                        book2[x][y]=idx;
                        book[x][y].x=book[t.x][t.y].x+dir[k][0];
                        book[x][y].y=book[t.x][t.y].y+dir[k][1];
                        v.push_back({book[x][y].x,book[x][y].y});
                        q.push({x,y});
                    }
                }

                int flag=1;
                for(int p=0;p<n;p++){
                    if(!flag)break;
                    for(int q=0;q<m;q++){
                        if(book2[p][q]!=idx&&g[p][q]=='.'){
                            flag=0;
                            for(auto [a,b]:v){
                                if(p+a<0||p+a>=n||q+b<0||q+b>=m||g[p+a][q+b]=='O'){
                                    flag=1;
                                    break;
                                }
                            }
                            if(!flag){
                                break;
                            }
                        }
                    }
                }
                if(flag)ans+=cnt;
            }
        }
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
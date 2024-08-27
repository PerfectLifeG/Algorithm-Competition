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
int dir[4][2]={1,0,-1,0,0,1,0,-1};
void solve(){
    int n,m;cin>>n>>m;
    char g[n][m];int p=0;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        for(int j=0;j<m;j++){
            g[i][j]=s[j];
            if(s[j]=='.')p++;
        }
    }
    if(p==n*m){
        cout<<"Blue\n";
        return;
    }else if(p==0){
        cout<<"Red\n";
        return;
    }
    int book[n][m]={};
    int idx=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(book[i][j]!=0&&book[i][j]<=idx||g[i][j]!='#')continue;
            idx++;
            int cnt=0;
            queue<PII>q;
            q.push({i,j});
            book[i][j]=idx;
            while(q.size()){
                auto t=q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int x=dir[k][0]+t.x,y=dir[k][1]+t.y;
                    if(x<0||y<0||x>=n||y>=m||book[x][y]==idx)continue;
                    book[x][y]=idx;
                    if(g[x][y]=='#'){
                        q.push({x,y});
                    }else cnt++;
                }
            }
            // cout<<i<<' '<<j<<' '<<cnt<<endl;
            if(cnt==p){
                cout<<"Red\n";
                return;
            }
        }
    }
    cout<<"Draw\n";
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
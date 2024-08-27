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
int dir[6][3]={1,0,0,0,1,0,0,0,1,-1,0,0,0,-1,0,0,0,-1};
void solve(){
    int m,n,l,t;cin>>m>>n>>l>>t;
    vector<vector<vector<int>>> g(m,vector<vector<int>>(n,vector<int>(l)));
    vector<vector<vector<int>>> book(m,vector<vector<int>>(n,vector<int>(l)));
    for(int i=0;i<l;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
                cin>>g[j][k][i];
            }
        }
    }

    auto bfs=[&](int a,int b,int c){
        queue<array<int,3>>q;
        q.push({a,b,c});
        int cnt=1;
        book[a][b][c]=1;
        while(q.size()){
            auto t=q.front();
            q.pop();
            for(int i=0;i<6;i++){
                int tx=t[0]+dir[i][0],ty=t[1]+dir[i][1],tz=t[2]+dir[i][2];
                if(tx<0||ty<0||tz<0||tx>=m||ty>=n||tz>=l||book[tx][ty][tz]||!g[tx][ty][tz])continue;
                book[tx][ty][tz]=1;
                cnt++;
                q.push({tx,ty,tz});
            }
        }
        if(cnt>=t)return cnt;
        return 0ll;
    };

    int ans=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<l;k++){
                if(!book[i][j][k]&&g[i][j][k]){
                    ans+=bfs(i,j,k);
                }
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
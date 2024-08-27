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
int dir[4][2]={0,1,0,-1,1,0,-1,0};
int book[310][310];
int g[310][310];
void solve(){
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
        }
    }

    auto check=[&](int mid){
        memset(book,0,sizeof(book));
        book[0][0]=1;
        queue<PII>q;
        q.push({0,0});
        while(q.size()){
            auto [x,y]=q.front();
            q.pop();
            if(x==n-1&&y==m-1)return 1;
            for(int i=0;i<4;i++){
                int tx=x+dir[i][0],ty=y+dir[i][1];
                if(tx<0||ty<0||tx>=n||ty>=m||book[tx][ty]||g[tx][ty]<mid)continue;
                book[tx][ty]=1;
                q.push({tx,ty});
            }
        }
        return 0;
    };

    int l=0,r=g[0][0]+1;
    while(l+1!=r){
        int mid=l+r>>1;
        if(check(mid))l=mid;
        else r=mid;
    }
    cout<<l<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
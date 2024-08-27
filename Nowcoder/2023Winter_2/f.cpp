#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
typedef pair<int,int> PII;
const int N=500010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int book[N][4];
void solve(){
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++)book[i][1]=book[i][2]=book[i][3]=0;
    while(k--){
        int a,b;cin>>a>>b;
        book[a][b]^=1;
    }
    function<int(int,int)> dfs=[&](int x,int y)->int{
        if(y+1<=3&&book[x][y+1]!=1){
            if(book[x][y+1]==3)book[x][y]=3;
            else if(book[x][y+1]==0){
                int t=dfs(x,y+1);
                if(book[x][y]==3);
                else if(t==3)book[x][y]=3;
                else book[x][y]=2;
            }
        }
        if(x+1<=n&&book[x+1][y]!=1){
            if(book[x+1][y]==3)book[x][y]=3;
            else if(book[x+1][y]==0){
                int t=dfs(x+1,y);
                if(book[x][y]==3);
                else if(t==3)book[x][y]=3;
                else book[x][y]=2;
            }
        }
        if(book[x][y]==3||(x==n&&y==3))return 3;
        return 0;
    };
    dfs(1,1);
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            if(book[i][j]==3)ans++;
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
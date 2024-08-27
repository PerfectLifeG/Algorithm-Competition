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
const int N=220;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
int g[N][4];
int cnt[N];
int now[3];
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++)cnt[i]=3;
    for(int i=1;i<=n;i++)g[i][1]=g[i][2]=g[i][3]=1;
    now[1]=now[2]=now[3]=n;
    int i=0;
    for(;i<n;i++){
        int a,b,c;cin>>a>>b>>c;
        if(cnt[a]==1)break;
        if(cnt[a]==2){
            if(g[a][2]==0||b==2)break;
        }
        g[a][b]=0;
        now[c]++;
        g[now[c]][c]=1;
        cnt[now[c]]++;
        cnt[a]--;
    }
    // cout<<i<<endl;
    if(i&1)cout<<"Sheauhaw\n";
    else cout<<"Nocriz\n";
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
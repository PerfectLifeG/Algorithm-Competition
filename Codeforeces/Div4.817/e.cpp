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
const int N=1001;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
int pre[N][N];
void solve(){
    int n,q;cin>>n>>q;
    memset(pre,0,sizeof pre);
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        pre[a][b]+=a*b;
    }
    for(int i=1;i<N;i++){
        for(int j=1;j<N;j++){
            pre[i][j]=pre[i][j]+pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
        }
    }
    while(q--){
        int a,b,c,d;cin>>a>>b>>c>>d;
        cout<<pre[c-1][d-1]-pre[c-1][b]-pre[a][d-1]+pre[a][b]<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
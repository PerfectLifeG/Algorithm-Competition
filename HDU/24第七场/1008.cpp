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
const int N=110;
const int mod=1e9+7;
const int INF=0x3f3f3f3f3f3f3f3f;

int n,m,L,R;
struct Matrix{
    int a[N][N];
    Matrix(int val){
        for(int i=1;i<=n+1;++i){
            for(int j=1;j<=n+1;++j){
                a[i][j]=val;
            }
        }
    }
    Matrix operator*(Matrix b){
        Matrix res(0);
        for(int i=1;i<=n+1;++i){
            for(int j=1;j<=n+1;++j){
                for(int k=1;k<=n+1;++k){
                    res.a[i][j]=(res.a[i][j]+a[i][k]*b.a[k][j]%mod)%mod;
                }
            }
        }
        return res;
    }
};

Matrix ksm(Matrix x,int k){
    Matrix res(0);
    for(int i=1;i<=n+1;++i)res.a[i][i]=1;
    while(k){
        if(k&1)res=res*x;
        k>>=1;
        x=x*x;
    }
    return res;
}

int ans[N];
int calc(Matrix a,int x){
    int t1=x/n;
    int t2=x%n;

    Matrix t=ksm(a,t1);
    // for(int i=1;i<=n+1;i++){
    //     for(int j=1;j<=n+1;j++){
    //         cout<<t.a[i][j]<<' ';
    //     }cout<<endl;
    // }
    // cout<<endl;

    int res=0;
    for(int i=1;i<=n+1;i++){
        res+=ans[i]*t.a[n+1][i]%mod;
        res%=mod;
    }
    // cout<<t2<<' '<<res<<endl;
    for(int i=1;i<=t2;i++){
        int tt=0;
        for(int j=1;j<=n+1;j++){
            tt+=ans[j]*t.a[i][j]%mod;
            tt%=mod;
        }
        // cout<<i<<' '<<tt<<endl;
        res+=tt;
        res%=mod;
    }
    return res;
}

void solve(){
    cin>>n>>m>>L>>R;
    for(int i=1;i<=n+1;i++)ans[i]=0;ans[1]=1;
    Matrix base(0);
    vector<vector<PII>> fa(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        if(v<=n)fa[v].push_back({u,w});
        else base.a[v-n][u]+=w;
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<base.a[i][j]<<' ';
    //     }cout<<endl;
    // }

    for(int i=1;i<=n;i++){
        for(auto [v,w]:fa[i]){
            ans[i]+=w*ans[v]%mod;
            ans[i]%=mod;
        }
    }

    for(int i=1;i<=n;i++){
        for(auto [v,w]:fa[i]){
            for(int j=1;j<=n;j++){
                base.a[i][j]+=base.a[v][j]*w%mod;
                base.a[i][j]%=mod;
            }
        }
    }
    for(int i=1;i<=n+1;i++)base.a[n+1][i]=1;


    cout<<(calc(base,R)-calc(base,L-1)+mod)%mod<<endl;

    // for(int i=1;i<=n+1;i++)cout<<ans[i]<<' ';cout<<endl;cout<<endl;
    // for(int i=1;i<=n+1;i++){
    //     for(int j=1;j<=n+1;j++){
    //         cout<<base.a[i][j]<<' ';
    //     }cout<<endl;
    // }

}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
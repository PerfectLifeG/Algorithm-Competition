#include<bits/stdc++.h>
using namespace std;
const int N = 100;
const int mod = 1e9+7;
typedef long long ll;
int n,m;
ll l,r;
struct Mat{
    int a[N+5][N+5];
    void init( ){
        memset(a,0,sizeof a);
    }
    void one(int n){
        memset(a,0,sizeof a);
        for(int i=1;i<=n;i++) a[i][i]=1;
    }
    Mat operator * (Mat b){
        Mat c;
        c.init();
        for(int i=1;i<=n+1;i++)
            for(int j=1;j<=n+1;j++)
                for(int k=1;k<=n+1;k++)
                    c.a[i][j]=(c.a[i][j]+1ll*a[i][k]*b.a[k][j]%mod)%mod;
    //    cout<<"Mat c:"<<"\n";
    //    c.print();
        return c;
    }
    void print(){
        for(int i=1;i<=n+1;i++){
            for(int j=1;j<=n+1;j++){
                cout<<a[i][j]<<" ";    
            }    
            cout<<"\n";
        }
    }
};
Mat qpow(Mat c,ll x){
    Mat ret;ret.one(n+1);
    while(x){
        if(x&1) ret=ret*c;
        c=c*c;
        x>>=1;
    //    cout<<x<<"\n";
    //    cout<<"Mat: c"<<"\n";
    //    c.print();
    }
    return ret;
}
ll work(Mat p,ll x,Mat o){
    ll t=x/n;
    ll r=x%n;
    //cout<<"t:"<<t<<"\n";
    p=qpow(p,t);
    ll ret=p.a[1][n+1];
    cout<<"!Mat p:"<<"\n";
    p.print();
    cout<<"!Mat o:"<<"\n";
    o.print();
    p=p*o;
    cout<<"!Mat p:"<<"\n";
    p.print();
    //cout<<"????"<<"\n";
    for(int i=1;i<=r;i++) ret=(ret+p.a[1][i])%mod;
    //cout<<x<<" ret:"<<ret<<"\n";
    cout<<ret<<endl;
    return ret;
}
void solve(){
    cin>>n>>m>>l>>r;
    Mat o,o1,o2,p;
    o.init();//初始矩阵
    o1.init();//层间转移
    o2.init();
    for(int i=1;i<=n+1;i++) o2.a[i][n+1]=1;//求和
    for(int i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        if(u<=n&&v<=n) o1.a[u][v]=w;
        else o2.a[u][v-n]=w;
    }
    // dp 一次
    cout<<"Mat o1:"<<"\n";
    o1.print();
    cout<<"Mat o2:"<<"\n";
    o2.print();
    o.one(n+1);
    cout<<"Mat o:"<<"\n";
    o.print();
    for(int i=n;i>=1;i--)
        for(int j=i;j<=n;j++)
            for(int k=j;k<=n;k++)
                o.a[i][k]=(o.a[i][k]+1ll*o.a[i][j]*o1.a[j][k]%mod)%mod;
    // 行间的转移
    
    cout<<"Mat o:"<<"\n";
    o.print();

    p=o*o2;

    cout<<"Mat p:"<<"\n";
    p.print();

    cout<<(work(p,r,o)-work(p,l-1,o)+mod)%mod<<"\n";
}
/*
2
3 4 5 6
1 2 1
1 3 1
3 4 1
2 5 1
5 8 998244353 1000000007
1 2 114514
1 4 1919810
2 3 999999999
3 5 111111111
4 5 1000000000
1 10 123456789
5 6 987654321
3 9 888888888
*/
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
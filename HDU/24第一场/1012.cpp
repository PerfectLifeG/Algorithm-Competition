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
const int N=4e3+10;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;

int ksm(int a,int n){
    int r=1ll;
    while(n){
        if(n&1)r=r*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return r;
}
int inv(int a){
    return ksm(a,mod-2);
}

int ans[N];
int pre[N][N];
int C[N][N];
unordered_map<int,int>mp1;
unordered_map<int,int>mp2;
void solve(){
    int n;scanf("%lld",&n);
    vector<int>row,col;
    vector<array<int,4>>v;
    for(int i=0;i<n;i++){
        int a,b,c,d;
        // cin>>a>>b>>c>>d;
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        v.push_back({a,b,c,d});
        row.push_back(a);row.push_back(c);
        col.push_back(b);col.push_back(d);
    }
    sort(all(row));sort(all(col));
    row.erase(unique(row.begin(),row.end()),row.end());
    col.erase(unique(col.begin(),col.end()),col.end());
    for(int i=0;i<row.size();i++)mp1[row[i]]=i;
    for(int i=0;i<col.size();i++)mp2[col[i]]=i;

    // for(auto i:row)cout<<i<<' '<<mp1[i]<<endl;
    // for(auto i:col)cout<<i<<' '<<mp2[i]<<endl;

    for(int i=0;i<n;i++){
        // cout<<i<<' '<<v[i][0]<<' '<<v[i][1]<<' '<<v[i][2]<<' '<<v[i][3]<<endl;
        // cout<<i<<' '<<mp1[v[i][0]]<<' '<<mp2[v[i][1]]<<' '<<mp1[v[i][2]]<<' '<<mp2[v[i][3]]<<endl;
        int x1=mp1[v[i][0]]+1,y1=mp2[v[i][1]]+1;
        int x2=mp1[v[i][2]]+1,y2=mp2[v[i][3]]+1;
        pre[x1][y1]++;
        pre[x1][y2]--;
        pre[x2][y1]--;
        pre[x2][y2]++;
        // cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
    }
    // for(int i=1;i<=row.size();i++){
    //     for(int j=1;j<=col.size();j++){
    //         cout<<pre[i][j]<<' ';
    //     }cout<<endl;
    // }
    // return;

    for(int i=1;i<row.size();i++){
        for(int j=1;j<col.size();j++){
            // cout<<i<<' '<<j<<' '<<pre[i][j]<<endl;
            pre[i][j]+=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
            // cout<<i<<' '<<j<<' '<<pre[i][j]<<endl;
            int h=row[i]-row[i-1],l=col[j]-col[j-1];
            ans[pre[i][j]]+=h*l%mod;
            ans[pre[i][j]]%=mod;
            // cout<<i<<' '<<j<<' '<<h<<' '<<l<<' '<<pre[i][j]<<endl;
        }
    }
    // for(int i=1;i<=row.size();i++){
    //     for(int j=1;j<=col.size();j++){
    //         cout<<pre[i][j]<<' ';
    //     }cout<<endl;
    // }
    // return;

    for(int k=1;k<=n;k++){
        int res=0;
        int x=inv(C[n][k])%mod;
        for(int i=1;i<=n;i++){
            res+=(1-(C[n-i][k]*x)%mod+mod)%mod*ans[i]%mod;
            res%=mod;
        }
        printf("%lld\n",res);
        // cout<<res<<endl;
    }

}
signed main(){
    // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    for(int i=0;i<2e3+10;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++){
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
        }
    }
    while(_--)solve();
    return 0;
}
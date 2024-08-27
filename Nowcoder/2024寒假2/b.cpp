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
const int INF=0x3f3f3f3f;
void solve(){
    int n,m,k;cin>>n>>m>>k;
    // vector<int>row(n+2);
    // vector<int>col(m+2);
    int book[n+2][m+2]={};
    int ans=k*4;
    while(k--){
        int a,b;cin>>a>>b;
        book[a][b]++;
        // if(row[a+1])ans--;
        // if(row[a+1])ans--;
        // col[b]++;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(book[i][j]&&book[i+1][j])ans--;
            if(book[i][j]&&book[i][j+1])ans--;
        }

    }
    // for(int i=1;i<=m;i++){
    //     if(col[i]&&col[i+1])ans--;
    // }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
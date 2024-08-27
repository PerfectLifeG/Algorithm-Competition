#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
struct node{
    int a;
    int b;
}a[N];
void solve()
{
    int n;cin>>n;
    string s[n+1];
    for(int i=1;i<=n;i++){
        cin>>s[i];
        s[i]=' '+s[i];
    }
    vector<int>dg(2*n+1),adg(2*n+1);
    int d[n+1][n+1]={};
    int ans=0;
    string a;cin>>s;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int a;cin>>a;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            d[i][j]=(dg[i+j]+adg[i-j+n]+d[i-1][j])&1;
            s[i][j]^=d[i][j];
            if(s[i][j]=='1'){
                dg[i+j]++;
                adg[i-j+n]++;
                d[i][j]++;
                ans++;
            }
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
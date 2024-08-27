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
void solve(){
    int n;cin>>n;
    vector<vector<int>>pre (n+1,vector<int>(30));
    vector<vector<int>>suf (n+2,vector<int>(30));
    vector<vector<int>>pre2 (n+2,vector<int>(30));
    vector<vector<int>>suf2 (n+2,vector<int>(30));
    vector<vector<int>>pre3 (n+2,vector<int>(30));
    vector<vector<int>>suf3 (n+2,vector<int>(30));
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int j=0;j<30;j++){
        for(int i=1;i<=n;i++){
            pre[i][j]=pre[i-1][j]+(a[i]>>j&1);
            pre2[i][j]=pre2[i-1][j]+(pre[i][j]&1);
            pre3[i][j]=pre3[i-1][j]+(1^(pre[i][j]&1));
        }
    }
    for(int j=0;j<30;j++){
        for(int i=n;i>=1;i--){
            suf[i][j]=suf[i+1][j]+(a[i]>>j&1);
            suf2[i][j]=suf2[i+1][j]+(suf[i][j]&1);
            suf3[i][j]=suf3[i+1][j]+(1^(suf[i][j]&1));
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int l,r;
        int zj,zo,yj,yo;
        for(int j=30;j>=0;j--){
            if(a[i]>>j&1){
                l=suf2[1][j]-suf2[i+1][j];
                r=pre2[n][j]-pre2[i][j];
                if(suf2[i][j]&1)l=suf3[1][j]-suf3[i+1][j];
                if(pre2[i][j]&1)r=pre3[n][j]-pre3[i][j];
                ans+=l*(n-i+1-r)+r*(i-l);
                // cout<<j<<' '<<l<<' '<<r<<endl;
                break;
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
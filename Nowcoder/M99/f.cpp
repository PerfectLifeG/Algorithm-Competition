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
    int n,m,t;cin>>n>>m>>t;
    vector<int>a(m);
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    t-=n;
    if(t<0){
        cout<<0<<endl;
        return;
    }

    sort(all(a));
    vector<int>book(n+1);
    for(int i=1;i<m;i++){
        book[a[i]-a[i-1]]=1;
    }
    // cout<<t<<endl;
    // return;
    vector<int>dp(t+1);dp[0]=1;
    for(int i=1;i<=n;i++){
        if(!book[i])continue;
        for(int j=i*2;j<=t;j++){
            dp[j]|=dp[j-i*2];
        }
        for(int j=i;j<=n;j+=i){
            book[j]=0;
        }
    }
    
    for(int i=t;i>=0;i--){
        if(dp[i]){
            cout<<i+n<<endl;
            return;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
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
    int n,m;cin>>n>>m;
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int d=i;d<=n;d+=i){
            int r=n/d;r=min(r,d-1);
            for(int x=1;x<=r;x++){
                int y=d/i-x;
                if(y<1)break;
                if(y*d>m||__gcd(x,y)!=1)continue;
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
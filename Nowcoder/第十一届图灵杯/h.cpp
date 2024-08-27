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
    int n,d;cin>>n>>d;
    vector<int>v(n+1);
    vector<int>p(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    int ans=d;
    v[d]+=p[1];
    int lst=2;
    for(int i=d-1;i>=1;i--){
        int t=v[d]-v[i];
        if(t<0)break;
        while(lst<=n&&p[lst]>t)lst++;
        if(lst==n+1)break;
        ans=i;
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
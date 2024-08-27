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
const int N=500010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
int nx[N*60][2],cnt[N*60],idx=1;
void solve(){
    int n,k1,k2;cin>>n>>k1>>k2;
    k2=min(k2,(int)60);
    if(k1>=60){cout<<0<<endl;return;}
    vector<int>a(n+1);
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    auto insert=[&](int x,int val){
        int t=0;
        for(int i=k2-1;i>=k1;i--){
            int j=x>>i&1;
            if(!nx[t][j])nx[t][j]=idx++;
            t=nx[t][j];
            cnt[t]=val;
        }
    };
    auto query=[&](int x){
        int t=0,res=0;
        for(int i=k2-1;i>=k1;i--){
            int j=x>>i&1;
            if(nx[t][!j])res=max(res,cnt[nx[t][!j]]);
            if(!nx[t][j])return res;
            t=nx[t][j];
        }
        return res;
    };

    int at=1;
    insert(a[1],1);
    for(int i=2;i<=n;i++){
        if((a[i]>>k2)==(a[i-1]>>k2)){
            ans+=query(a[i]);
            insert(a[i],i-at+1);
        }else{
            while(at<i)insert(a[at++],0);
            insert(a[i],i-at+1);
        }
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
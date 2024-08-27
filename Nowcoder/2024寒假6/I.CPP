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
    vector<int>a(n+1);
    vector<int>dpa(n+1);
    vector<int>b(m+1);
    vector<int>dpb(m+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    int mxa=a[1];
    int mna=a[1];
    int mxb=b[1];
    int mnb=b[1];
    for(int i=1;i<=n;i++){
        dpa[i]=max(dpa[i-1]+a[i],a[i]);
        mxa=max(mxa,dpa[i]);
    }
    for(int i=1;i<=m;i++){
        dpb[i]=max(dpb[i-1]+b[i],b[i]);
        mxb=max(mxb,dpb[i]);
    }
    dpa.assign(n,INF);
    dpb.assign(m,INF);
    for(int i=1;i<=n;i++){
        dpa[i]=min(dpa[i-1]+a[i],a[i]);
        mna=min(mna,dpa[i]);
    }
    for(int i=1;i<=m;i++){
        dpb[i]=min(dpb[i-1]+b[i],b[i]);
        mnb=min(mnb,dpb[i]);
    }
    // cout<<mna<<' '<<mnb<<' '<<mxa<<' '<<mxb<<endl;
    cout<<max({mxa*mxb,mna*mnb,mxa*mnb,mxb*mna})<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
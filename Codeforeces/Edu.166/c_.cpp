#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin()+1,x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
#define x first
#define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n,m;cin>>n>>m;
    vector<int>a(n+m+2);
    vector<int>b(n+m+2);
    vector<int>f(n+m+2);
    for(int i=1;i<=n+m+1;i++){
        cin>>a[i];
    }
    int cnt=0;
    for(int i=1;i<=n+m+1;i++){
        cin>>b[i];
        if(a[i]>b[i])cnt++;
    }

    int ans[n+m+2];
    if(cnt>=n+1){
        int sn=0,sn1=0,sb=0,sb1=0;
        int c=0;
        for(int i=1;i<=n+m+1;i++){
            if(c<n&&a[i]>b[i])sn+=a[i],sn1+=a[i],c++,f[i]=1;
            else if(c<n+1&&a[i]>b[i])sn1+=a[i],sb1+=b[i],c++,f[i]=1;
            else sb+=b[i],sb1+=b[i];
        }
        for(int i=1;i<=n+m+1;i++){
            if(f[i]) ans[i]=sn1+sb-a[i];
            else ans[i]=sn+sb1-b[i];
        }
    }else{
        int sn=0,sn1=0,sb=0,sb1=0;
        int c=0;
        for(int i=1;i<=n+m+1;i++){
            if(c<m&&a[i]<=b[i])sn+=b[i],sn1+=b[i],c++,f[i]=1;
            else if(c<m+1&&a[i]<=b[i])sn1+=b[i],sb1+=a[i],c++,f[i]=1;
            else sb+=a[i],sb1+=a[i];
        }
        for(int i=1;i<=n+m+1;i++){
            if(f[i]) ans[i]=sn1+sb-b[i];
            else ans[i]=sn+sb1-a[i];
        }
    }

    for(int i=1;i<=n+m+1;i++)cout<<ans[i]<<' ';cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
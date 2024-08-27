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
void solve(){
    int n,t;cin>>n>>t;
    if(t==0){
        cout<<0<<endl;
        return;
    }
    vector<int>a(n+1);
    vector<int>b(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    vector<int>k(n+1);
    for(int i=1;i<=n;i++){
        int z=b[i];
        for(int j=1;j<=t;j++){
            k[j]+=(j&1?1:-1)*a[i]*z,z*=b[i];
        }
    }
    for(int i=1;i<t;i++){
        if(k[i]){puts("infinity");return;}
    }
    int z=t;
    int d=__gcd(k[t],z);
    k[t]/=d;z/=d;
    if(z==1)cout<<k[t]<<endl;
    else cout<<k[t]<<'/'<<z<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
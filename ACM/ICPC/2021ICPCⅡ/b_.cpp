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
    int n;cin>>n;
    vector<int>a(n+2);
    vector<int>b(n+2);
    vector<int>c(n+2);
    vector<int>c2(n+2);
    vector<int>ans1(n+2);
    vector<int>ans(n+2);
    vector<int>ans2(n+2);
    vector<int>sg(n+2);
    for(int i=1;i<=n;i++){
        cin>>sg[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    for(int i=1;i<=n;i++){
        if(sg[i]==1){
            ans1[i]=(a[i]+b[i]+c[i-1])%2;
            c[i]=(a[i]+b[i]+c[i-1])/2;
        }else{
            ans2[i]=(a[i]+b[i]+c2[i-1])%2;
            c2[i]=(a[i]+b[i]+c2[i-1])/2;
        }
    }
    for(int i=1;i<=n;i++){
        
    }
    cout<<ans[1]-ans2[1];
    for(int i=2;i<=n;i++){
        cout<<' '<<ans[i]-ans2[i];
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
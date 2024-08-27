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
    vector<int>ans(n+2);
    vector<int>sg(n+2);
    for(int i=1;i<=n;i++){
        cin>>sg[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        ans[i]=a[i]+b[i];
    }
    int now=0;
    for(int i=1;i<=n;i++){
        if(ans[i]>=2){
            if(sg[i]==sg[i+1]){
                ans[i+1]+=ans[i]/2;
                ans[i]%=2;
            }else{
                ans[i+1]-=ans[i]/2;
                ans[i]%=2;
            }
        }else if(ans[i]<=-1){
            if(sg[i]==sg[i+1]){
                ans[i+1]-=(-ans[i]+1)/2;
                ans[i]=(ans[i]%2+2)%2;
            }else{
                ans[i+1]+=(-ans[i]+1)/2;
                ans[i]=(ans[i]%2+2)%2;
            }
        }
    }
    cout<<ans[1];
    for(int i=2;i<=n;i++){
        cout<<' '<<ans[i];
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
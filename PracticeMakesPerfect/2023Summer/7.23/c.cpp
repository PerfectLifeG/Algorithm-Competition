#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
int a[N];
void solve()
{
    int n,k;cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int op1=0,op2=0;
    while(k--){
        int b,c;
        cin>>b>>c;
        if(b==1){op1+=c;}
        else {op2+=max(0ll,c-op1);op1-=min(c,op1);}
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=op1;
        ans%=mod;
    }
    for(int i=0;i<n;i++){
        ans+=max(0ll,a[i]-op2);
        ans%=mod;
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    // cin>>_;
    while(_--)solve();
    return 0;
}
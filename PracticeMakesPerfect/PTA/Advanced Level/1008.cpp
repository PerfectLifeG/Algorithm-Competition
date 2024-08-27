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
void solve()
{
    int n;cin>>n;
    int lst=0;
    int ans=0;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        if(a>lst)ans+=6*(a-lst);
        else if(a<lst)ans+=4*(lst-a);
        lst=a;
    }
    ans+=n*5;cout<<ans<<endl;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    // cin>>_;
    while(_--)solve();
    return 0;
}
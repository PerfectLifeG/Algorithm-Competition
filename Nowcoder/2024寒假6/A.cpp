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
    int l,r;cin>>l>>r;
    for(int i=l;i<=r;i++){
        int t=i;
        int cnt2=0;
        int ans=t;
        for(int j=2;j<=t/j;j++){
            int cnt=0;
            if(t%j==0){
                t/=j;
                cnt++;
            }
            if(cnt>1)break;
            else cnt2++;
        }
        if(t>1)cnt2++;
        if(cnt2==3){cout<<ans<<endl;return;}
    }
    cout<<-1<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int a,b,c;cin>>a>>b>>c;
    int t=0;
    int aa=1;
    int ans=1e18;
    while(aa<=c){
        ans=min(ans,(c-aa)/aa*b+b*bool((c-aa)%aa)+b+a*t);
        t++;
        aa*=2;
    }
    cout<<min(ans,a*t+b)<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
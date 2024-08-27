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
    int n,k;cin>>n>>k;
    int cnt=0;
    int t=1;
    while(cnt<k){
        int l=0,r=n/2+2;
        while(l+1!=r){
            int mid=l+r>>1;
            if(t*(2*mid-1)<=n)l=mid;
            else r=mid;
        }
        if(cnt+l>=k){
            cout<<t*(2*(k-cnt)-1)<<endl;
            break;
        }
        cnt+=l;
        t*=2;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
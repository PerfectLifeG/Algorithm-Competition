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
    int x,q;cin>>x>>q;
    int t=1;
    int xx=x;
    while(xx){
        xx/=2;
        t*=2;
    }
    vector<int>v(t+1);
    vector<int>s(t+1);
    // cout<<t<<endl;
    for(int i=1;i<=t;i++){
        v[i]=(__gcd((x*i)^x,x)==1);
    }
    for(int i=1;i<=t;i++){
        s[i]=s[i-1]+v[i];
    }
    while(q--){
        int a,b;cin>>a>>b;
        __int128 l=a,r=b;
        if(x%2==0){
            cout<<0<<endl;
            continue;
        }
        __int128 ll=l/t;
        __int128 rr=r/t;
        // cout<<ll<<' '<<l%t<<' '<<rr<<' '<<r%t<<endl;
        __int128 p=(int)(rr-ll)*s[t];
        if(l%t==0)l=-(s[t]-s[t-1]);
        else l=s[l%t-1];
        r=s[r%t];
        // cout<<p<<' '<<l<<' '<<r<<endl;
        cout<<(int)(p+r-l)<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
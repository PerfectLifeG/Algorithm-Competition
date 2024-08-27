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
string s;
struct hash{
    #define ll unsigned long long
    const int P=131;
    ll h[N];
    ll p[N];
    void init(){
        int len=s.size()-1;
        p[0]=1;
        for(int i=1;i<=len;i++){
            h[i]=(h[i-1]*P+s[i]);
            p[i]=p[i-1]*P;
        }
    }
    int get(int l,int r){
        ll res=h[r]-h[l-1]*p[r-l+1];
        return res;
    }
}hs;
void solve(){
    cin>>s;
    s=' '+s;
    hs.init();
    int n=s.size()-1;
    int ans=0;
    for(int i=1;i<n;i++){
        int l1=i,r1=i;
        int l2=i+1,r2=i+1;
        while(l1>=1&&r2<=n){
            if(hs.get(l1,r1)==hs.get(l2,r2)){
                ans++;
                r1=l1-1;
                l2=r2+1;
            }
            l1--,r2++;
        }
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
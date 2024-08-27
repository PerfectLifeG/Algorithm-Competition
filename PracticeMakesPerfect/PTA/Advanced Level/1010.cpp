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
string a,b;
unordered_map<char,int>mp;
int t=0;
int cal(int j){
    int r=0;
    int p=1;
    for(int i=b.size()-1;i>=0;i--){
        r+=mp[b[i]]*p;
        if(r>t||r<0)return 1e18;//爆int了！
        p*=j;
    }
    // cout<<t<<' '<<r<<endl;
    return r;
}
void solve(){
    int tag,q;cin>>a>>b>>tag>>q;
    for(int i=0;i<26;i++)mp['a'+i]=i+10;
    for(int i=0;i<10;i++)mp['0'+i]=i;
    if(tag==2)swap(a,b);
    int p=1;
    for(int i=a.size()-1;i>=0;i--){
        t+=mp[a[i]]*p;
        p*=q;
    }
    int mx=1;
    for(auto i:b)mx=max(mx,mp[i]);
    int l=mx,r=t+10;
    if(l+1>r){
        puts("Impossible");
        return;
    }
    while(l+1!=r){
        int mid=l+r>>1;
        if(cal(mid)>=t)r=mid;
        else l=mid;
    }
    if(cal(r)==t)cout<<r<<endl;
    else puts("Impossible");
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
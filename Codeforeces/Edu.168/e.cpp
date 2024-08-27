#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
int tr[N];
void add(int t,int val){
    for(int i=t;i<N;i+=lowbit(i)){
        tr[i]+=val;
    }
}
int query(int t){
    int res=0;
    for(int i=t;i;i-=lowbit(i)){
        res+=tr[i];
    }
    return res;
}
void solve(){
    int n,q;cin>>n>>q;
    vector<int>a(n+1);
    vector<int>ans(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        int l=-1,r=n+1;
        while(l+1!=r){
            int mid=l+r>>1;
            if(query(mid)<a[i]*mid)r=mid;
            else l=mid;
        }
        add(r,1);
        ans[i]=r;
    }
    while(q--){
        int pos,k;cin>>pos>>k;
        if(ans[pos]<=k)yes;
        else no;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
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
struct BIT {
    #define lowbit(x) (x&(-x))
    int n;
    vector<int>tr;
    BIT(int size){
        n = size;
        tr.resize(size + 5, 0);
    }
    void add(int t,int val){
        for(int i=t;i<=n;i+=lowbit(i)){
            tr[i]+=val;
        }
    }
    int query(int t){
        int ret=0;
        for(int i=t;i;i-=lowbit(i)){
            ret+=tr[i];
        }
        return ret;
    }
};
void solve(){
    int n;cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    BIT tr(N);
    int ans=0;
    for(int i=1;i<=n;i++){
		tr.add(a[i],1);
		cout<<N<<' '<<tr.query(N)<<' '<<2*a[i]<<' '<<tr.query(2*a[i])<<endl;
		ans+=tr.query(N)-tr.query(2*a[i]-1);
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
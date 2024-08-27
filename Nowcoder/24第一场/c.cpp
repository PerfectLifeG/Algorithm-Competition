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
const int N=500010;
const int mod=1e9+7;
const int INF=0x3f3f3f3f3f3f3f3f;
struct BIT {
    #define lowbit(x) (x&(-x))
    int n;
    vector<int>tr;
    BIT(int size){
        n = size;
        tr.resize(size + 1, 0);
    }
    void add(int t,int val){
        for(int i=t;i<=n;i+=lowbit(i)){
            tr[i]+=val;
            tr[i]%=mod;
        }
    }
    int query(int t){
        int res=0;
        for(int i=t;i;i-=lowbit(i)){
            res+=tr[i];
            res%=mod;
        }
        return res;
    }
};
void solve(){
    BIT tr(N);
    int Q;cin>>Q;
    vector<int>v;
    while(Q--){
        int a,b;cin>>a>>b;
        int t=v.size();
        for(int i=1;i<=a;i++){
            tr.add(t-i+1,(-tr.query(t-i+1)+tr.query(t-i)));
        }
        for(int i=0;i<a;i++){
            v.pop_back();
        }
        v.push_back(b);
        int n=v.size();
        tr.add(n,n*b%mod);
        cout<<tr.query(N-1)%mod<<endl;
    }

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
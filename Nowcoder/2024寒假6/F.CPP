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
const int N=1000100;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
struct DSU {
    std::vector<int> f;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return ;
        }
        if(x>y)swap(x,y);
        f[y] = x;
    }
};
vector<int>prime;
int book[N];
void get_prime(int n=N-1){
    for(int i=2;i<=n;i++){//枚举k
        if(!book[i])prime.push_back(i);
        for(int j=0;prime[j]*i<=n;j++){//p*k<=n
            book[prime[j]*i]=1;
            if(i%prime[j]==0)break;//k不包含比p小的质因子
        }
    }
}
void solve(){
    int n;cin>>n;
    unordered_map<int,int>mp;int idx=n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        int t=a[i];
        for(auto j:prime){
            if(j>t/j)break;
            if(t%j==0){
                if(!mp.count(j))mp[j]=idx++;
            }
            while(t%j==0){
                t/=j;
            }
        }
        if(t>1)if(!mp.count(t))mp[t]=idx++;
    }
    DSU dsu(idx+1);
    for(int i=0;i<n;i++){
        int t=a[i];
        for(auto j:prime){
            if(j>t/j)break;
            if(t%j==0){
                dsu.merge(i,mp[j]);
            }
            while(t%j==0){
                t/=j;
            }
        }
        if(t>1)dsu.merge(i,mp[t]);
    }

    int cnt=0;
    for(int i=0;i<n;i++){
        if(dsu.find(i)==i)cnt++;
    }
    if(cnt>=2){
        vector<int>ans;
        vector<int>ans2;
        for(int i=0;i<n;i++){
            if(dsu.find(i)==0){
                ans.push_back(a[i]);
            }else ans2.push_back(a[i]);
        }
        cout<<ans.size()<<' '<<ans2.size()<<endl;
        for(auto i:ans)cout<<i<<' ';cout<<endl;
        for(auto i:ans2)cout<<i<<' ';cout<<endl;
    }else cout<<"-1 -1\n";
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    get_prime(1000000);
    cin>>_;
    while(_--)solve();
    return 0;
}
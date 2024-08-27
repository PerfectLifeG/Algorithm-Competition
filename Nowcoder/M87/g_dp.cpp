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
    #define lowbit(x) (x&-x)
    int n;
    vector<int>tr;
    BIT(int size){
        n = size;
        tr.resize(size + 1, 0);
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
vector<int>divs[N];
void get_divisor(int n=N-1){
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            divs[j].push_back(i);
        }
    }
}

void solve(){
    int n;cin>>n;
    get_divisor(n);
    vector<int>a(n+1);
    vector<int>v[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(auto j:divs[a[i]]){
            v[j].push_back(a[i]);
        }
    }
    int ans=0;
    BIT tr(n);
    vector<int>dp(n+1);
    for(int i=n/2;i>=1;i--){//这个排列的最大公因数<=n/2所以从n/2开始枚举即可
        for(int j=v[i].size()-1;j>=0;j--){
            tr.add(v[i][j],1);
            dp[i]+=tr.query(v[i][j]-1);
        }
        for(int j=v[i].size()-1;j>=0;j--)
            tr.add(v[i][j],-1);

        for(int j=i+i;j<=n;j+=i){
            dp[i]-=dp[j];
        }
    }

    cout<<dp[1]<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
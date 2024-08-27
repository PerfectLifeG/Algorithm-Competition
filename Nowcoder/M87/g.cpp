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

int mo[N];
int book[N];
int prime[N],cnt;
void mobius(int n=N-1){
    mo[1]=1;
    for(int i=2;i<=n;i++){//枚举k
        if(!book[i]){
            prime[cnt++]=i;
            mo[i]=-1;//质数的mo=-1
        }
        for(int j=0;prime[j]*i<=n;j++){//p*k<=n
            book[prime[j]*i]=1;
            if(i%prime[j]==0){//其质因数至少包含两个prime[j]，故mo=0
                mo[prime[j]*i]=0;
                break;
            }
            mo[prime[j]*i]=-mo[i];//质因数互不相同
        }
    }
}
int mp[N];
void solve(){
    int n;cin>>n;
    mobius(n);
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]]=i;
    }
    int ans=0;
    BIT tr(n);
    for(int i=1;i<=n;i++)if(mo[i]!=0)
    {
        vector<int>v;
        for(int j=i;j<=n;j+=i){
            v.push_back(j);
        }
        sort(all(v),[&](int a,int b){
            return mp[a]>mp[b];
        });
        for(auto j:v){
            tr.add(j,1);
            ans+=mo[i]*tr.query(j-1);
        }
        for(auto j:v)tr.add(j,-1);
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
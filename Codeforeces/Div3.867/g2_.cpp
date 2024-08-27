#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=1e3+1,M=33000;
const int mod=998244353;
const int INF=0x3f3f3f3f;
vector<int>prime;
vector<int>divs[M];
int book[N];
void getprime(int n){
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
    map<int,int>mp;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        mp[a]++;
    }
    ll ans=0;
    for(auto [x,y]:mp){
        ans+=1ll*y*(y-1)*(y-2);
        int val=1;
        int t=x;
        for(auto p:prime){
            int f=0;
            while(t%p==0){
                if(f&1){
                    val*=p;
                }
                t/=p;
                f^=1;
            }
        }
        if(t>1){
            int tt=sqrt(t);
            if(tt*tt==t)val*=tt;
        }
        for(auto q:divs[val]){
            if(mp.count(x/q)&&mp.count(x/q/q))
                ans+=1ll*y*mp[x/q]*mp[x/q/q];
        }
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    bitset<N> is_pr;
    is_pr.set();
    for (int i = 2; i < N; i++) {
        if (is_pr[i]) {
            prime.push_back(i);
            for (int j = i * i; j < N; j += i) {
                is_pr[j] = 0;
            }
        }
    }
    for(int i=2;i<M;i++){
        for(int j=i;j<M;j+=i){
            divs[j].push_back(i);
        }
    }
    while(_--)solve();
    return 0;
}
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
vector<int>prime;
int book[N];
int cnt;
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
    int a,b;cin>>a>>b;
    if(b%a==0){
        cout<<0<<endl;
        return;
    }
    if(a>=b){
        cout<<(a-b)<<endl;
        return;
    }
    int ans=INF;
    for(auto i:prime){
        ans=min(ans,a%i+i-(b%i));
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    getprime(1e4);
    while(_--)solve();
    return 0;
}
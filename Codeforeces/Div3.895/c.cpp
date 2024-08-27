#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=1e7+1;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int prime[N];
int book[N];
int cnt;
void getprime(int n){
    for(int i=2;i<=n;i++){//枚举k
        if(!book[i])prime[cnt++]=i;
        for(int j=0;prime[j]*i<=n;j++){//p*k<=n
            book[prime[j]*i]=1;
            if(i%prime[j]==0)break;//k不包含比p小的质因子
        }
    }
}
void solve(){
    int l,r;cin>>l>>r;
    int ll=l,rr=r;
    while(r>=l){
        if(r%2==0&&r!=2){
            cout<<r/2<<' '<<r/2<<endl;return;
        }
        r--;
    }
    if(rr==ll){
        int i=2;
        for(;i<=ll/i;i++){
            if(ll%i==0){
                break;
            }
        }
        if(ll%i!=0){
            cout<<-1<<endl;
            return;
        }
        return;
    }
    cout<<-1<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
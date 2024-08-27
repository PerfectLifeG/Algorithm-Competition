#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int phi[N],cnt;
int book[N];
int primes[N];
void Euler(int n){       
    // phi[1]=1;
    for(int i=2;i<=n;i++){
        if(!book[i]){
            primes[cnt++]=i;
            phi[i]=i-1;//质数的欧拉函数=本身-1
        }
        for(int j=0;primes[j]<=n/i;j++){
            book[primes[j]*i]=1;
            if(i%primes[j]==0){//其质因数至少包含两个prime[j]
                phi[primes[j]*i]=primes[j]*phi[i];//由欧拉函数phi[i]与质因数次数没有关系
                break;
            }
            phi[primes[j]*i]=(primes[j]-1)*phi[i];//质因数互不相同
        }
    }
}
void solve(){
    int n;cin>>n;
    Euler(n);
    for(int i=1;i<=n;i++)cout<<phi[i]<<' ';cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    // cin>>_;
    while(_--)solve();
    return 0;
}
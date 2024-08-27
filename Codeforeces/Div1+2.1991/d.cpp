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
vector<int>prime;
int book[N];
vector<int>v[N];
void get_prime(int n=N-1){
    for(int i=2;i<=n;i++){
        if(!book[i])prime.push_back(i);
        for(int j=0;prime[j]*i<=n;j++){//p*i<=n
            // book[prime[j]*i]=1;
            v[i].push_back(prime[j]*i);
            if(i%prime[j]==0)break;//i不包含比p小的质因子
        }
    }
}
int val[N];
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cout<<val[i]<<' ';
    }
    cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    get_prime();
    for(int i=1;i<N;i++){
        val[i]=1;
    }
    for(int i=1;i<N;i++){
        cout<<i<<':'<<endl;
        for(auto j:prime){
            if(j>i&&){
                if(val[j]==val[i]){
                    val[j]=val[i]+1;
                }
            }
            // cout<<j<<' ';
        }
        cout<<endl;
    }
    cin>>_;
    while(_--)solve();
    return 0;
}
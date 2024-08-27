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
const int N=1e7;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
vector<int>prime;
int book[N];    
void get_prime(int n=N-1){
    for(int i=2;i<=n;i++){
        if(!book[i])prime.push_back(i);
        for(int j=0;prime[j]*i<=n;j++){//p*i<=n
            book[prime[j]*i]=1;
            if(i%prime[j]==0)break;//i不包含比p小的质因子
        }
    }
}
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]=1;
    }
    for(int i=0;i<=n;i++){
        if(!mp.count(prime[i])){
            cout<<prime[i]<<endl;
            return;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    get_prime();
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
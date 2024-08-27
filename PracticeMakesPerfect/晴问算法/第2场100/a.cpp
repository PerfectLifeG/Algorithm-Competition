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
    for(int i=2;i<=n;i++){//枚举k
        if(!book[i])prime.push_back(i);
        for(int j=0;prime[j]*i<=n;j++){//p*k<=n
            book[prime[j]*i]=1;
            if(i%prime[j]==0)break;//k不包含比p小的质因子
        }
    }
}
void solve(){
    int n=prime.size();
    vector<int>s(n+1);
    s[0]=prime[0];
    for(int i=1;i<n;i++){
        s[i]=s[i-1]+prime[i];
    }
    int q;cin>>q;
    while(q--){
        int l,r;cin>>l>>r;
        int l1=lower_bound(all(prime),l)-prime.begin();
        int r1=prev(upper_bound(all(prime),r))-prime.begin();
        if(l1==0)cout<<s[r1]<<endl;
        else cout<<s[r1]-s[l1-1]<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    get_prime();
    while(_--)solve();
    return 0;
}
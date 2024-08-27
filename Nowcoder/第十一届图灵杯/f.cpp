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
const int N=100010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
int book[N];
int book2[N];
int f[N];
vector<int>prime;
void fun(){
    int n=N-1;
    for(int i=2;i<=n;i++){
        if(!book[i])prime.push_back(i);
        for(int j=0;prime[j]*i<=n;j++){
            book[prime[j]*i]=1;
            if(i%prime[j]==0)break;
        }
    }
}
void solve(){
    int n;cin>>n;
    fun();
    for(int i=1;i<=N;i++){
        int t=(1+i)*i/2;
        // cout<<t<<endl;
        if(t>n)break;
        book2[t]=1;
    }
    f[0]=1;
    for (int i = 1; i <= N; i++) {
        f[i] = f[i - 1] * (4 * i - 2) / (i + 1);
        if(f[i]>n)break;
        book2[f[i]]=1;
        // cout<<i<<' '<<f[i]<<endl;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(i%2==0)continue;
        if(!book[i])continue;
        if(book2[i])continue;
        ans++;
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
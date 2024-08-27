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
int ksm(int a,int n){
    int r=1ll;
    while(n){
        if(n&1)r=r*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return r;
}
int inv(int a){
    return ksm(a,mod-2);
}
vector<int>divs[N];
void divisor(int n=N){
    for(int i=1;i<n;i++){
        for(int j=i;j<n;j+=i){
            divs[j].push_back(i);
        }
    } 
}
int val[N];
int cnt[N];
void solve(){
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    for(int i=0;i<n;i++){
        for(auto j:divs[v[i]]){
            cnt[j]++;
        }
    }

    int ans=0;
    for(int i=0;i<n;i++){
        for(auto j:divs[v[i]]){
            cnt[j]--;
            int t=cnt[j];
            if(t!=0){
                ans+=val[j]%mod*(((t+1)*t%mod*inv(2))%mod)%mod;ans%=mod;
                ans+=val[j]%mod*t%mod;ans%=mod;
            }
        }
    }
    for(int i=0;i<n;i++){
        ans+=v[i];ans%=mod;
    }
    int t=n*(n+1)%mod*inv(2)%mod;
    cout<<ans*inv(t)%mod<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    divisor();
    for(int i=1;i<=N;i++)val[i]=i;
    for(int i=2;i<N;i++){
        val[i]-=divs[i][divs[i].size()-2];
        if(val[i]<0)val[i]=0;
        val[i]=(val[i]+mod)%mod;
    }
    while(_--)solve();
    return 0;
}
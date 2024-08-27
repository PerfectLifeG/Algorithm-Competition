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
const int N=1e7+1;
const int mod=998244353;
const int INF=0x3f3f3f3f;
vector<int>prime;
unordered_map<int,int>book;
map<int,int>mp;
int cnt;
int n;
// void getprime(int n=N-1){
//     for(int i=2;i<=n;i++){
//         if(!book[i]){
//             prime.push_back(i);
//             mp[i]+=n+1-i;
//         }
//         for(int j=0;prime[j]*i<=n;j++){
//             book[prime[j]*i]=1;
//             mp[prime[j]]+=n+1-(prime[j]*i);
//             mp[i]+=n+1-(prime[j]*i);
//             if(i%prime[j]==0)break;
//         }
//     }
// }
void solve(){
    cin>>n;
    // getprime();
    cout<<"f("<<n<<")=";
    int first=1;
    int book[n+1]={};
    for(int i=2;i<=n;i++){
        if(book[i])continue;
        book[i]=1;
        int t=0;
        for(int j=i;j<=n;j+=i){
            int p=j;
            while(p%i==0){
                t+=(n+1-j);
                p/=i;
            }
            book[j]=1;
        }
        if(first){
            if(t==1)cout<<i;
            else if(t>1)cout<<i<<'^'<<t;
            first=0;
        }else{
            if(t==1)cout<<'*'<<i;
            else if(t>1)cout<<'*'<<i<<'^'<<t;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
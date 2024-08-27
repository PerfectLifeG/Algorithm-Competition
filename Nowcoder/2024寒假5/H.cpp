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
const int N=2e3+10;
const int M=1e6+10;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
vector<int>prime;
int book2[N];
void get_prime(int n=N-1){
    for(int i=2;i<=n;i++){//枚举k
        if(!book2[i])prime.push_back(i);
        for(int j=0;prime[j]*i<=n;j++){//p*k<=n
            book2[prime[j]*i]=1;
            if(i%prime[j]==0)break;//k不包含比p小的质因子
        }
    }
}
int match[N];
int e[M],h[M],ne[M],idx;
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
bool find(int t,vector<int>& book){
    for(int i=h[t];i!=-1;i=ne[i]){
        int j=e[i];
        if(book[j]==0){
            book[j]=1;
            if(match[j]==0||find(match[j],book)){
               match[j]=t;
               return true;
            }
        }
    }
    return false;
}
void solve(){
    int n;cin>>n;
    get_prime(2*n);
    memset(h,-1,sizeof(h));
    int id;
    for(int i=1;i<=n;i++){
        if(!book2[i+n]){
            id=i;break;
        }
    }
    for(int i=id;i<=n;i++){
        ans[i]=n-i-id;
    }

    for(int i=1;i<id;i++){
        vector<int>book(id+1);
        find(i,book);
    }
    vector<int>ans(n+1);
    for(int i=1;i<id;i++){
        ans[match[i]]=i;
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
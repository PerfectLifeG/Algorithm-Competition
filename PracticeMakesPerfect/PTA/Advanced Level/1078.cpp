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
int cnt;
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
    get_prime();
    int t,n;cin>>t>>n;
    t=*lower_bound(all(prime),t);
    vector<int>book(t);
    int first=1;

    auto check=[&](int a){
        if(book[a%t]){
            for(int i=0;i<t;i++){
                if(!book[(a+i*i)%t]){
                    book[(a+i*i)%t]=1;
                    return (a+i*i)%t;
                }
            }
            return (int)-1;
        }else{
            book[a%t]=1;
            return a%t;
        }
    };

    for(int i=0;i<n;i++){
        int a;cin>>a;
        if(first){
            int p=check(a);
            if(p==-1) cout<<"-";
            else cout<<p;
            first=0;
        }else{
            int p=check(a);
            if(p==-1) cout<<" -";
            else cout<<' '<<p;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
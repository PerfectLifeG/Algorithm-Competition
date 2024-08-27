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
const int N=1e7+10;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;


vector<int>prime;
int book[N];    
int sg[N];
int idx=1;
void get_prime(int n=N-1){
    for(int i=2;i<=n;i++){
        if(!book[i]){prime.push_back(i);sg[i]=idx++;}
        for(int j=0;prime[j]*i<=n;j++){//p*i<=n
            book[prime[j]*i]=1;
            sg[prime[j]*i]=sg[prime[j]];
            if(i%prime[j]==0)break;//i不包含比p小的质因子
        }
    }
}


void solve(){
    int n;cin>>n;
    int ans=0;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        if(x%2==0)continue;
        // cout<<x<<' '<<sg[x]<<endl;
        ans^=sg[x];
    }
    if(ans)cout<<"Alice\n";
    else cout<<"Bob\n";



    // for(int i=0;i<N;i++)book[i]=0;
    // prime.clear();
    // get_prime();
    // vector<int>sg2(200);
    // sg2[1]=1;
    // for(int i=2;i<200;i++){
    //     if(i%2==0)continue;
    //     if(!book[i]){
    //         int cnt=0;
    //         for(int j=2;j<=i;j++){
    //             if(!book[j])cnt++;
    //         }
    //         sg2[i]=cnt;
    //     }else{
    //         for(auto j:prime){
    //             if(i%j==0){
    //                 sg2[i]=sg2[j];
    //                 break;
    //             }
    //         }
    //     }
    //     // cout<<i<<' '<<sg2[i]<<endl;
    //     if(sg[i]!=sg2[i])cout<<i<<' '<<sg[i]<<' '<<sg2[i]<<endl;
    // }


}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;


    get_prime();
    // int idx=2;
    // for(int i=3;i<N;i++)if(!book[i])book[i]=idx++;
    // idx=4;
    sg[1]=1;
    // for(int i=1;i<N;i++){
    //     // if(i%2==0)sg[i]=0;
    //     // else if(book[i]!=1)sg[i]=book[i];
    //     // else sg[i]=idx++;
    //     cout<<i<<' '<<sg[i]<<endl;
    // }

    while(_--)solve();
    return 0;
}
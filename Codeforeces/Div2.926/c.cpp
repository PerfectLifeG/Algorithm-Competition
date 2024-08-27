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
const int INF=0x3f3f3f3f;
void solve(){
    int k,x,a;cin>>k>>x>>a;
    // int flag=1;
    // for(int i=1;i<=x;i++){
    //     if(a-i<=0){flag=0;break;}
    //     if(k<=i+1){
    //         flag=0;
    //         break;
    //     }
    // }
    // if(flag){yes;return;}
    // // if(a-x>0&&k>x&&(a-x)*k>a){
    // //     yes;
    // //     return;
    // // }
    // int t=(1+x+1)*x+1/2;
    
    // if(a-t<=0){
    //     no;
    //     return;
    // }
    int sum=1;
    for(int i=1;i<=x;i++){
        sum+=sum/(k-1)+1;
        if(sum>a){
            no;
            return;
        }
    }
    if(sum<=a)yes;
    else no;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
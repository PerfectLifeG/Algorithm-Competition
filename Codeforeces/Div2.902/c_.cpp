#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n,m,k;cin>>n>>m>>k;
    if(k>3){
        cout<<0<<endl;
        return;
    }
    int a=m/n;
    int b=m%n;
    int t1,t2,t3=0;
    t1=1;
    if(a>=1){
        t3=(a-1)*(n-1)+b;
        t2=(a-1)+n;
    }


    if(a==0){
        t3=0;
        t2=b;
    }

    // cout<<t1<<' '<<t2<<' '<<t3<<endl;
    if(k==1){
        cout<<t1<<endl;
        return;
    }
    if(k==2){
        cout<<t2<<endl;
        return;
    }
    if(k==3){
        cout<<t3<<endl;
        return;
    }

    // 1 2 
    // 4 5
    // 6 7
    // 8 9
    // 10
    // 10/3=3

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    // freopen("output.txt","w",stdout);
    cin>>_;
    while(_--)solve();
    return 0;
}
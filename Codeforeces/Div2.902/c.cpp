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
    // int n,m,k;cin>>n>>m>>k;
    // if(k>3){
    //     cout<<0<<endl;
    //     return;
    // }
    int n=6;
    vector<int>a(n+2);

    for(int j=0;j<=17;j++){
        a[n+1]=j;
        cout<<a[n+1]<<' ';
        for(int i=n;i>=1;i--){
            a[i]=a[i+1]%i;
            cout<<a[i]<<' ';
        }cout<<endl;
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
    freopen("output.txt","w",stdout);
    // cin>>_;
    while(_--)solve();
    return 0;
}
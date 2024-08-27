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
    int n,k,a,b;cin>>n>>k>>a>>b;
    int t=0;
    vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            // t^=a[i];
        }
    if(n%2==0){
            cout<<2<<endl;
        for(int i=0;i<2;i++){
            cout<<1<<' '<<n<<endl;
        }}
    else {
        cout<<4<<endl;
        for(int i=0;i<2;i++)
        cout<<1<<' '<<n-1<<endl;
         for(int i=0;i<2;i++)
        cout<<n-1<<' '<<n<<endl;
    }

    // while(1){
    //     if(t==0)break;
    // }
    // if(t!=0)
    // cout<<t<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
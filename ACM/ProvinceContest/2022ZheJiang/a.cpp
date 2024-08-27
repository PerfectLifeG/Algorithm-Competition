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
        int a,b;cin>>a>>b;
        if(a<b){
            if((b-a)&1){
                cout<<1<<endl;
            }else{
                int t=b-a;
                if((t/2)&1) cout<<2<<endl;
                else cout<<3<<endl;
            }
        }else if(a>b){
            if((a-b)&1){
                cout<<2<<endl;
            }else cout<<1<<endl;
        }else{
            cout<<0<<endl;
        }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
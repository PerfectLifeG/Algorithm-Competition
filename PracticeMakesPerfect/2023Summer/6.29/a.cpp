#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
void solve(){
    int n,k,x;cin>>n>>k>>x;
    if(k==1){
        no;
        return;
    }
    if(x!=1){
        yes;
        cout<<n<<endl;
        for(int i=0;i<n;i++){
            cout<<1<<' ';
        }
        cout<<endl;
        return;
    }
    // 3 k1
    // 3>=2
    // 3 3 1
    if(n%2==0){
        if(k>=2){
            yes;
            cout<<n/2<<endl;
            for(int i=0;i<n/2;i++){
                cout<<2<<' ';
            }
            cout<<endl;
            return;
        }
    }
    else {
        if(k>=3){
            yes;
            cout<<n/2<<endl;
            for(int i=0;i<n/2-1;i++){
                cout<<2<<' ';
            }
            cout<<3<<endl;
            return;
        }
    }
    no;

}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
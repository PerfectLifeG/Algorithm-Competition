#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
void solve(){
    int a,b;cin>>a>>b;
    if(a==0||b==0){
        cout<<2<<endl;
        cout<<1<<' '<<1<<endl;
        cout<<a<<' '<<b<<endl;
    }
    else if(b==1||a==1){
        cout<<1<<endl;
        cout<<a<<' '<<b<<endl;
    }
    else {
        cout<<2<<endl;
            cout<<a-1<<' '<<1<<endl;
        
        cout<<a<<' '<<b<<endl;
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
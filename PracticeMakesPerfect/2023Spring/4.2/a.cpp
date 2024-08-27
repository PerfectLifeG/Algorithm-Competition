#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
void solve(){
    int n;cin>>n;
    int ret;cin>>ret;
    for(int i=1;i<n;i++){
        int a;cin>>a;
        ret^=a;
    }
    if(n%2==0)if(ret){cout<<-1<<endl;return;}
    cout<<ret<<endl;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
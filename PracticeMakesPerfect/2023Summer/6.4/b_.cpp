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
int a[N];
void solve(){
    int n;cin>>n;
    int aa,bb;
    int cc;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1)aa=i;
        if(a[i]==2)bb=i;
        if(a[i]==n)cc=i;
    }
    if(aa<cc&&cc<bb||bb<cc&&cc<aa){
        cout<<"1 1"<<endl;
        return;
    }
    if(aa>bb){    
        if(cc>aa){
            cout<<aa<<' '<<cc<<endl;
        }else{
            cout<<bb<<' '<<cc<<endl;
        }
    }else{
        if(cc>bb){
            cout<<bb<<' '<<cc<<endl;
        }else cout<<aa<<' '<<cc<<endl;
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
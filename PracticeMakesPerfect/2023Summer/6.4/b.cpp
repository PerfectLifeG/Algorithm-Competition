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
    if(abs(aa-bb+1)==n)cout<<"1 1"<<endl;
    else{
        if(aa>bb){
            if(n-aa>bb-1){
                cout<<aa<<' '<<n<<endl;
                return;
            }else{
                cout<<bb<<' '<<1<<endl;
                return;
            }
        }else{
            if(n-bb>aa-1){
                cout<<bb<<' '<<n<<endl;
                return;
            }else{
                cout<<aa<<' '<<1<<endl;
                return;
            }
        }
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
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
int c[N];
void solve(){
    int n,m,k,b;cin>>n>>m>>k>>b;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    m--;
    for(int i=0;i<n;i++){
        // cout<<'-'<<a[i]<<' '<<c[i]<<' '<<k<<endl;
        int tt=1,t=1;
        if(k>b)
            tt=(k-b)/c[i]+(bool)((k-b)%c[i]);
        if(k>a[i])
            t=(k-a[i])/c[i]+(bool)((k-a[i])%c[i]);
        
        // cout<<tt<<' '<<t<<endl;
        if(t>=m){
            cout<<a[i]+m*c[i]<<' ';
            continue;
        }else{
            // m-=t;
            int p=m-t;
            // cout<<m<<endl;
            if(p%tt==0){
                cout<<b<<' ';continue;
            }else{
                cout<<b+p%tt*c[i]<<' ';
                continue;
            }
        }
    }
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
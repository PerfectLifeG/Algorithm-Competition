#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
int a[N],s[N];
void solve(){
    int n;cin>>n;
    // for(int i=1;i<=n;i++){
    //     cin>>a[i];
    //     s[i]=a[i]+s[i-1];
    //     a[i]=(a[i]+s[i-1])%n;
    // }
    if(n==1){
        cout<<1<<endl;
        return;
    }
    if(n&1){
        cout<<-1<<endl;
        return;
    }
    a[1]=n;a[2]=n-1;a[3]=2;
    // a[3]=a[1]-a[2];a[4]=n+1-a[3];a[5]=a[1]-a[4];
    for(int i=4;i<=n;i++){
        if(i%2==0)a[i]=a[2]-a[i-1];
        else a[i]=n+1-a[i-1];
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
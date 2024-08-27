#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
int a[N];
void solve(){
    int n;cin>>n;
    if(n==1){
        cout<<1<<endl;
        return;
    }
    // if(n&1){
    //     cout<<-1<<endl;
    //     return;
    // }
    int s=0;
    for(int i=1;i<=n;i++){
        a[i]=i;
        s+=a[i];
    }
    if(s%n==0){
        cout<<-1<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        if(i&1){
            swap(a[i],a[i+1]);
        }
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
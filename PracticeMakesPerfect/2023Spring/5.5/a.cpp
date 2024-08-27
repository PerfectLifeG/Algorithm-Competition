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
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }   
    sort(a+1,a+n+1);
    for(int i=n;i>0;i--){
        if(a[n-i+1]>i){
            cout<<i<<endl;
            return;
        }else if(a[n-i+1]==i){
            cout<<-1<<endl;
            return;
        }
    }
    if(a[n]==0)cout<<0<<endl;
    else cout<<-1<<endl;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
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
    cin>>a[0];
    cout<<1;
    int idx=1;
    int flag=1;
    for(int i=1;i<n;i++){
        cin>>a[idx];
        if(flag){
            if(a[idx]>=a[idx-1]&&a[idx-1]>=a[0]){cout<<1;idx++;}
            else if(a[idx]<=a[idx-1]&&a[idx]<=a[0]){cout<<1;idx++;flag=0;}
            else {cout<<0;}
        }else{
            if(a[idx]<=a[0]&&a[idx]>=a[idx-1]){cout<<1;idx++;}
            else cout<<0;
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
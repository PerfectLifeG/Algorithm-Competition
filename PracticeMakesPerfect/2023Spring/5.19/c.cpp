#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353,INF=1e9+10;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
int a[N];
void solve(){
    int n;cin>>n;
    set<int>s;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]&1){
            s.insert(a[i]);
        }
    }
    // for(auto i:s){
    //     cout<<i<<' ';
    // }
    // cout<<endl;
    int flag=1;
    for(int i=0;i<n;i++){
        if(a[i]&1){
            if((s.lower_bound(a[i]))==s.begin()){
                // no;
                flag=0;
                // return;
            }
        }
    }
    if(flag){
        yes;
        return;
    }
    for(int i=0;i<n;i++){
        if(!(a[i]&1)){
            if((s.lower_bound(a[i]))==s.begin()){
                no;
                return;
            }
        }
    }
    yes;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
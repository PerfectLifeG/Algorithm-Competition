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
int a[N],ans[N];
void solve(){
    int n;cin>>n;
    int idx,idx2;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==n){
            idx=i;
        }
        if(a[i]==n-1){
            idx2=i;
        }
    }
    if(n==1){
        cout<<a[0]<<endl;
        return;
    }
    if(idx!=0){
        int j=0;
        for(int i=idx;i<n;i++){
            ans[j++]=a[i];
        }
        if(idx!=n-1){
            idx--;
            ans[j++]=a[idx];
        }
        idx--;
        while(a[idx]>a[0]){
            ans[j++]=a[idx];
            idx--;
        }
        for(int i=0;i<=idx;i++){
            ans[j++]=a[i];
        }
    }else{
        int j=0;
        for(int i=idx2;i<n;i++){
            ans[j++]=a[i];
        }
        if(idx2!=n-1){
            idx2--;
            ans[j++]=a[idx2];
        }
        idx2--;
        while(a[idx2]>a[0]){
            ans[j++]=a[idx2];
            idx2--;
        }
        for(int i=0;i<=idx2;i++){
            ans[j++]=a[i];
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<' ';
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
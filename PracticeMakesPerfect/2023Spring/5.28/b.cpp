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
    int mx=0;
    unordered_map<int,int>mp;
    unordered_map<int,int>mp2;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;){
        int j=i+1;
        while(j<n&&a[i]==a[j]){
            j++;
        }
        if(mp.count(a[i])==0){mp[a[i]]=0;}
        mp[a[i]]=max(mp[a[i]],j-i);
        i=j;
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;){
        int j=i+1;
        while(j<n&&a[i]==a[j]){
            j++;
        }
        if(mp2.count(a[i])==0){mp2[a[i]]=0;}
        mp2[a[i]]=max(mp2[a[i]],j-i);
        mx=max(mx,mp2[a[i]]+mp[a[i]]);
        i=j;
    }
    cout<<mx<<endl;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
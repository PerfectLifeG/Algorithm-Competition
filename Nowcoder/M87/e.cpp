#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int mx=a[0];
    for(int i=0;i<n;i++){
        cout<<mx-a[0]<<' ';
        mx=max(mx,a[i]);
    }
    // int flag=1;
    // for(int i=1;i<n;i++){
    //     if(a[i]<a[i-1]){flag=0;break;}
    // }
    // if(flag){
    //     for(int i=0;i<n;i++)cout<<0<<' ';
    //     return;
    // }
    // int i=0;
    // for(;i<n;i++){
    //     if(a[i]>a[i+1])break;
    // }
    // int j=n-1;
    // for(;j>=0;j--){
    //     if(a[j]<a[j-1])break;
    // }
    // int mx=a[i];
    // for(int k=i;k<=j-1;k++){
    //     mx=max(mx,a[k]);
    // }
    // for(int k=0;k<=i;k++){
    //     if(a[k]<=mx)cout<<0<<' ';
    //     else cout<<mx-a[k]<<' ';
    // }
    // for(int k=i+1;k<j;k++){
    //     cout<<mx-a[k]<<' ';
    // }
    // for(int k=j;k<n;k++){
    //     if(a[k]>=mx)cout<<0<<' ';
    //     else cout<<mx-a[k]<<' ';
    // }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
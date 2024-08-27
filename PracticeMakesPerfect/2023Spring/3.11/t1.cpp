#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1000100;
int a[N];
int book[N];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){cin>>a[i];book[a[i]]++;}
    int ans=0;
    for(int i=0;i<N;i++){
        if(book[i]>=2)ans+=book[i]*(book[i]-1);
    }
    cout<<ans+n;
    return 0;
}
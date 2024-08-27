#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1000100;
int a[N];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int ans=0;
    for(int i=n-1;i>=0;i-=2){
        ans+=a[i];
    }
    cout<<ans<<endl;
    return 0;
}
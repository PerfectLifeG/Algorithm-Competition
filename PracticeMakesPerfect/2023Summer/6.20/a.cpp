#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
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
    int ans=0;
    int f1=0,f2=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        ans+=abs(a[i]);
    }
    for(int i=0;i<n;){
        if(a[i]==0){i++;continue;}
        int j=i+1;
        while(j<n&&(a[j]==0||a[j]*a[i]>0))j++;
        if(a[i]>0)f1++;
        if(a[i]<0)f2++;
        i=j;
    }
    cout<<ans<<' '<<min(f2,f1+1)<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
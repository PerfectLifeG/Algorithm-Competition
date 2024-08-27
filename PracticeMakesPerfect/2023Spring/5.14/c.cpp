#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=1e9+7;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
// int a[N],b[N];
int cmp(int a,int b){
    return a>b;
}
void solve(){
    int n;cin>>n;
    vector<int>a(n+1);
    vector<int>b(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    sort(all(a));
    sort(all(b),cmp);
    int cnt=0;
    long long ans=1;
    for(int i=0;i<n;i++){
        auto x=upper_bound(a.begin()+1,a.end(),b[i]);
        if(x==a.end()){
            cout<<0<<endl;
            return;
        }
        int y=x-a.begin();
        y=n-y;
        ans=ans*(y-cnt+1)%mod;
        cnt++;
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
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
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    int ans=0;
    s[n]=s[n-1];
    for(int i=0;i<n;){
        int j=i+1;
        // int t=0;
        while(j<n&&s[j]==s[i]){
            j++;
        }
        // cout<<i<<' '<<j<<'.'<<endl;
        ans=max(ans,j-i);
        i=j;
    }
    cout<<ans+1<<endl;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
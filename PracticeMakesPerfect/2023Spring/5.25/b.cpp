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
    int ans=1;
    for(int i=0;i<n;i++){
        int j=i+1;
        while(s[j]==s[i]){
            j++;
            ans++;
        }
        int t=j;
        while(j<n&&t-i>=j-t&&s[j]!=s[i]){
            j++;
        }
        i=j;
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
#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl

void solve(){
    int n;cin>>n;
    string s;cin>>s;
    map<char,int>mp;
    int flag=-1;int ans=0;
    for(int i=0;i<n;i++){
        mp[s[i]]++;
        if(mp.size()==2&&flag==-1)flag=i;
        if(flag>=0&&mp.begin()->first==s[i]){
            flag=i;
            ans=1;
        }
    }
    if(flag==-1||!ans){cout<<s<<endl;return;}
    cout<<s[flag];
    for(int i=0;i<n;i++){
        if(i!=flag)cout<<s[i];
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
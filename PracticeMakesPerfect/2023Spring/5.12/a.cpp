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
    string s;
    cin>>s;
    unordered_map<char,int>mp;
    int cnt=0;
    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
    }
    int cnt2=0;
    for(auto i:mp){
        if((i.second)&1){
            if(i.second>1)cnt2++;
            cnt++;
        }
    }
    if(cnt==1&&(s.size()&1)||cnt==0){
        if(mp.size()==2&&cnt==1&&cnt2==0||mp.size()==1){
            no;
            return;
        }
        yes;
        return;
    }
    no;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
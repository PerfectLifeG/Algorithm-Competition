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
    if(n&1){
        cout<<-1<<endl;
        return;
    }
    map<char,int>mp1;//每个字母冲突次数
    map<char,int>mp2;//每个字母出现次数
    int mxcnt=0,cnt=0;//字母最大出现次数，冲突总次数
    for(int i=0;i<n;i++){
        mp2[s[i]]++;
        mxcnt=max(mxcnt,mp2[s[i]]);
        if(i<n/2&&s[i]==s[n-i-1]){
            mp1[s[i]]++;
            cnt++;
        }
    }
    if(mxcnt>n/2){
        cout<<-1<<endl;
        return;
    }
    int mx=0;//字母最大冲突次数
    for(auto it:mp1)mx=max(mx,it.second);
    if(mx<=cnt/2){
        cout<<(cnt+1)/2<<endl;
    }else cout<<mx<<endl;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
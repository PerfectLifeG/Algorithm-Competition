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
        return ;
    }
    map<char,int>mp;//冲突字母
    map<char,int>mp2;//可用字母
    int k=0,cnt=0;//可用总次数，冲突总次数
    for(int i=0;i<n/2;i++){
        if(s[i]==s[n-i-1]){
            cnt++;
            mp[s[i]]++;
        }else {mp2[s[i]]++;mp2[s[n-i-1]]++;k+=2;}
    }
    int mx1=0;char c;//字母最大冲突次数
    if(cnt){
        for(auto it:mp){
            if(mx1<it.second){
                mx1=it.second;
                c=it.first;
            }
        }
        // aacaabad
        int mx2=(cnt+1)/2;
        // cout<<cnt<<' '<<mx1<<' '<<mx2<<endl;
        if(mx1>=mx2){
            if((k-mp2[c]*2)/2<mx1-(cnt-mx1))cout<<-1<<endl;
            else cout<<mx1<<endl;
        }
        else cout<<mx2<<endl;
    }else{
        cout<<0<<endl;
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
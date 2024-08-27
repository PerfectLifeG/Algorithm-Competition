#include<bits/stdc++.h>
using namespace std;
const int N=10010;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        string s;cin>>s;
    unordered_map<char,char>mp;
        int flag=1;
        mp[s[0]]='1';
        s[0]='1';
        for(int i=1;i<s.size();i++){
            if(mp.count(s[i])){
                s[i]=mp[s[i]];
            }else{
                if(s[i-1]=='1'){mp[s[i]]='0';s[i]='0';}
                else {mp[s[i]]='1';s[i]='1';}
            }
            if(s[i]==s[i-1]){flag=0;break;}
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    string s;cin>>s;
    unordered_map<char,int>mp;
    unordered_map<char,char>nx;
    unordered_map<char,int>mx;
    for(int i=0;i<s.size();){
        int j=i+1;
        int cnt=1;
        while(j<s.size()&&s[j]==s[i]){
            j++;
            cnt++;
        }
        mp[s[i]]+=cnt;
        mx[s[i]]=max(mx[s[i]],cnt);
        nx[s[i]]=s[j];
        i=j;
    }
    for(char c='a';c<='z';c++){
        if(mx.count(c)){
            if(mx[c]!=mp[c]){
                cout<<string(c,mx[c]+1)<<endl;
                return;
            }else if(){
                
            }
        }else{
            c++;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
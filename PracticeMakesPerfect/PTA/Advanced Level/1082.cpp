#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    string s;cin>>s;
    unordered_map<char,string>mp;
    mp['1']=" yi";mp['2']=" er";mp['3']=" san";mp['4']=" si";mp['5']=" wu";
    mp['6']=" liu";mp['7']=" qi";mp['8']=" ba";mp['9']=" jiu";mp['0']=" ling";
    string ans="";
    if(s=="0"){cout<<"ling";return;}
    if(s[0]=='-'){cout<<"Fu ";s=s.substr(1);}
    int cnt=1;
    for(int i=s.size()-1;i>=0;i--){
        if(i!=s.size()-1&&s[i]=='0'&&s[i+1]!='0')ans.insert(0," ling");
        if(s[i]!='0'&&cnt==2)ans.insert(0," Shi");
        if(s[i]!='0'&&cnt==3)ans.insert(0," Bai");
        if(s[i]!='0'&&cnt==4)ans.insert(0," Qian");
        if(cnt==5)ans.insert(0," Wan");
        if(s[i]!='0'&&cnt==6)ans.insert(0," Shi");
        if(s[i]!='0'&&cnt==7)ans.insert(0," Bai");
        if(s[i]!='0'&&cnt==8)ans.insert(0," Qian");
        if(s[i]!='0'&&cnt==9)ans.insert(0," Yi");
        if(s[i]!='0')ans.insert(0,mp[s[i]]); 
        cnt++;
    }
    cout<<ans.substr(1)<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
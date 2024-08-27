#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<string,string> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
char p[4]={'C','D','H','S'};
unordered_map<char,int>mp;
void solve(){
    int n;cin>>n;
    char op[2];cin>>op;
    vector<int>book[4];
    for(int i=0;i<2*n;i++){
        string s;cin>>s;
        book[mp[s[1]]].push_back(s[0]-'0');
    }
    vector<PII>ans;
    int idx=0;int flag=1;
    for(int i=0;i<4;i++){
        sort(all(book[i]));
        // cout<<i;
        // for(auto j:book[i])cout<<' '<<j;cout<<endl;
    }
    for(int i=0;i<4;i++){
        if(!flag)break;
        if(i!=mp[*op]){
            for(int j=0;j<book[i].size();j+=2){
                if(j+1<book[i].size()){
                    string s1="";s1+=char('0'+book[i][j]);s1+=p[i];
                    string s2="";s2+=char('0'+book[i][j+1]);s2+=p[i];
                    ans.push_back({s1,s2});
                }
                else {
                    if(idx<book[mp[*op]].size()){
                        string s1="";s1+=char('0'+book[i][j]);s1+=p[i];
                        string s2="";s2+=char('0'+book[mp[*op]][idx++]);s2+=(*op);
                        ans.push_back({s1,s2});
                    }
                    else flag=0;
                }
            }
        }
    }
    if(!flag||(book[mp[*op]].size()-idx)&1){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    for(int j=idx;j<book[mp[*op]].size();j+=2){
        string s1="";s1+=char('0'+book[mp[*op]][j]);s1+=(*op);
        string s2="";s2+=char('0'+book[mp[*op]][j+1]);s2+=(*op);
        ans.push_back({s1,s2});
    }
    for(auto [i,j]:ans)cout<<i<<' '<<j<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    mp['C']=0;
    mp['D']=1;
    mp['H']=2;
    mp['S']=3;
    cin>>_;
    while(_--)solve();
    return 0;
}